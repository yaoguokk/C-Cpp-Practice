Select student_name as name, stu_id from Student_registration
Where student_name not in (select student_name from Student_registration where status = 'IP')
Group by student_name
order by stu_id Asc; 
