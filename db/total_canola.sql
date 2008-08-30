select count(id) from submissions where page_id in (select id from pages where corpus_id=7);
