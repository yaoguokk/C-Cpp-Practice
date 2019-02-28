select Chef from Chefskill
where Dish in (select * from Menu)
group by Chef
having count(Chef) = (select count(*) from Menu)
