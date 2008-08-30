select count(distinct submissions.page_id) as cunique,
       count(submissions.id) as ctotal,
       name 
from submissions, users
where users.id=user_id and
      page_id in (select id from pages where corpus_id=5)
group by user_id
order by cunique desc;
