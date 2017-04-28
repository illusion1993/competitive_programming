from bs4 import BeautifulSoup
import urllib2

url = "https://cdn.hackerrank.com/hackerrank/static/contests/capture-the-flag/infinite/"
all_links = {}
messages = []

def traverse(s):
	all_links[unicode(s)] = 1
	resp = urllib2.urlopen("{0}{1}".format(url, s))
	soup = BeautifulSoup(resp, from_encoding=resp.info().getparam('charset'))

	message = soup.find("font", color="blue")
	if message:
		messages.append(message.text)
		for m in messages:
			print m

	for link in soup.find_all('a', href=True):
		if not all_links.get(unicode(link['href'])):
			print(link['href'])
			traverse(unicode(link['href']))

traverse("qds.html")
messages.sort()
print all_links
print("SORTED MESSAGES:---------------------")
for m in messages:
	print m
