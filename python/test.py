import re
text1 = "V-RP @OZRP_ +?MVw, @AU, R18+?"

author = re.findall("@[\w]+", text1)
print(author)
