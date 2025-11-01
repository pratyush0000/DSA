# Important things to remember

1. how to get year? eg. where year = 2010;

```sql
select count(patient_id) from patients where year(birth_date) = 2010;
```

2. how to get rows of patient ids? eg. 1,45,xxxx.

```sql
select * from patients where patient_id in (1,45,534,879,1000);
```

3. Show unique first names from the patients table which only occurs once in the list.

```sql
SELECT first_name
FROM patients
GROUP BY first_name
HAVING COUNT(first_name) = 1
```

4. how to order by multiple things

```sql
select
  first_name,
  last_name,
  allergies
from patients
where
  allergies in ('Penicillin', 'Morphine')
order by
  allergies,
  first_name,
  last_name;
```

2.

```sql
select * from patients where patient_id in (1,45,534,879,1000);
```

2.

```sql
select * from patients where patient_id in (1,45,534,879,1000);
```
