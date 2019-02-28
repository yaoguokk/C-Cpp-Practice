select Employee.name, Bonus.bonus
from Employee
left join Bonus on Bonus.empId= Employee.empId
where bonus < 1000 or bonus is NULL
