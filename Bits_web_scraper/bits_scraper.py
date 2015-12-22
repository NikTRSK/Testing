# bits_scraper.py - bits.usc.edu scraper

import requests, os, bs4, re

#Downloads all files from a given URL to a subfolder
def download_files(url, path):

    response = requests.get(url)
    try:
        response.raise_for_status()
    except requests.exceptions.HTTPError as e:
        print "And you get an HTTPError:", e.message

    # Retrieve the webpage
    main = bs4.BeautifulSoup(response.content, "lxml")
    os.chdir(path) # change the directory

    # Get the Contents Table
    stylesheet = main.find('link', rel = 'stylesheet')
    tableFormatting = "<div id=\"content\" class=\"center\">"
    content = main.find('table')
    with open("_"+path+".html", "wb") as file:
        file.write(stylesheet.prettify("utf-8") + tableFormatting + content.prettify("utf-8"))

    # Get all pdfs
    itemList = main.findAll('a')
    for i in range(len(itemList)):
        if itemList[i].get('href').endswith(('.pdf', '.zip', '.rar')):
            os.system('wget -q -nd -np -c -N %s'%itemList[i].get('href'))

    # Get the HTML from assignments, labs
    linkList = main.find('table').findAll('tr')
    forDL = [] # Holds the links for download
    filenames = [] # Holds the filenames for the download
    for i in range (len(linkList)):
        try:
            if linkList[i].find('a').get('href').endswith('.html'):
                forDL.append(linkList[i].find('a').get('href'))
                filenames.append(linkList[i].find('a').text)
        except AttributeError:
            continue

    # Download the links
    for i in range (len(forDL)):
        response = requests.get(forDL[i])
        try:
            response.raise_for_status()
        except requests.exceptions.HTTPError as e:
            print "And you get an HTTPError:", e.message

        # Retrieve the webpage
        main = bs4.BeautifulSoup(response.content, "lxml")
    
        # Get the stylesheet for the page
        stylesheet = main.find('link', rel = 'stylesheet')
        # Get the content for the page
        content = main.find('div', id = 'main')
        print "Downloading ", filenames[i]
        html = stylesheet.prettify("utf-8") + '<meta charset="UTF-8">' + content.prettify("utf-8")
        with open(filenames[i]+".html", "wb") as file:
            file.write(html)

if __name__ == "__main__":
  url = 'http://bits.usc.edu/cs104/'

  res = requests.get(url)
  res.raise_for_status()

  # Retrieve the webpage
  main = bs4.BeautifulSoup(res.text, "lxml")

  # Create a folder with the website title
  root_dir = main.head.title.text
  if not os.path.exists(root_dir):
    os.makedirs(root_dir)
  os.chdir(root_dir)

  print "Downloading from ", main.head.title.text.encode('utf-8')
  # Look through the list of the main page
  menu = main.find_all('a')
  # Define search terms for extraction
  linksOfIntrest = ["Labs", "Lecture Schedule", "Assignments", "Homework"]
  for index in range(len(menu)):
    if any(s in menu[index].text for s in linksOfIntrest):
      # Create a folder for the category
      try:
        path = menu[index].li.string.replace('/', '-')
      except AttributeError:
        continue
      if not os.path.exists(path):
        os.makedirs(path)
      print "Exploring ", menu[index].li.string.encode('utf-8')
      
      # Explore the link
      url = menu[index].get('href')
      download_files(url, path)
      os.chdir('../')