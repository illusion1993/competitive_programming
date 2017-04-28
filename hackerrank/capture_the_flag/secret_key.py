import requests
import string
secrets = []

keys = requests.get('https://cdn.hackerrank.com/hackerrank/static/contests/capture-the-flag/secret/key.json')
keys = keys.json().keys()

for k in keys:
	r = requests.get('https://cdn.hackerrank.com/hackerrank/static/contests/capture-the-flag/secret/secret_json/{}.json'.format(k))
	print r.json()
	secrets.append(r.json()[u'news_title'])

secrets.sort()
for s in secrets:
	print s
