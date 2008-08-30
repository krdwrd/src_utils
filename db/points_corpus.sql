select users.id,
       count(distinct submissions.page_id) as cunique
from submissions, users
where users.id = user_id and
      page_id in (select id from pages where corpus_id=7)
group by user_id
order by users.id asc;
