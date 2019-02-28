select Chef from ChefSkill
inner join Menu on ChefSkill.Dish = Menu.Dish
Group by Chef
having count(*) = (select count(*) from Menu)
