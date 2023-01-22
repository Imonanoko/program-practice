name=input("Enter person's name:" )
hours_worked=int(input("Enter number of hours worked:"))
hourly_wage=int(input('Enter hourly wage:'))
class wages:
    def __init__(self,name,hours_worked,hourly_wage):
        self.name=name
        self.hours_worked=hours_worked
        self.hourly_wage=hourly_wage
    def count(self):
        if self.hours_worked<40:
            return self.hours_worked*self.hourly_wage
        else:
            return (self.hours_worked-40)*self.hourly_wage*1.5+40*self.hourly_wage
s=wages(name, hours_worked, hourly_wage)
print('pay for',name,':','{:,.2f}'.format(s.count()))
