select count(submissions.id) as cnt, name from submissions, users where users.id=user_id group by user_id order by cnt desc;
