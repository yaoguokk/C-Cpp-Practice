select a.student_name as Name  ,sum(units) as Units_complete from Student_registration a,Courses
where a.course=Courses.course AND a.student_name not in (select student_name from Student_registration where status = 'IP')
group by a.student_name
having sum(units)>10


