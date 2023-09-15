select * from albums order by name asc limit 20;

-- Sélectionner les titres des chansons de l'album "Forbidden"
select songs.title from songs
inner join albums on songs.album = albums._id
where albums.name = 'Forbidden';

-- Afficher toutes les chansons du groupe "Deep Purple"
select songs.title from songs
inner join albums on songs.album = albums._id
inner join artists on albums.artist = artists._id
where artists.name = 'Deep Purple';

-- Sélectionner les noms d'artiste dont le nom commence par "Me"
select artists.name from artists
where artists.name like "Me%";