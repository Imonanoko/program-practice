import requests
from bs4 import BeautifulSoup

url = "https://histock.tw/stock/rank.aspx"
html = requests.get(url)
sp = BeautifulSoup(html.text, 'html.parser')


datas = sp.find_all('td',limit=20)

                    

for i in datas:
      print(i.text,end="")

