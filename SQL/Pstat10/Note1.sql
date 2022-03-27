-- !preview conn=DBI::dbConnect(RSQLite::SQLite(),dbname="mtcars")


SELECT species_id, AVG(weight),COUNT(species_id)
FROM surveys
GROUP BY species_id