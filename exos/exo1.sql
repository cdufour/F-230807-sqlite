CREATE TABLE User (id integer primary key not null, name VARCHAR(50) not null, email VARCHAR(50) not null, is_admin BOOLEAN not null);
CREATE TABLE Post (id integer primary key not null, name VARCHAR(100) not null, text MEDIUMTEXT not null, author integer not null);

insert into User (name, email, is_admin) values ('Victor', 'vic@gmail.com', 1);
insert into Post (name,text,author) values ('Blabla','Blabla',1); 

-- La commande ci-dessous génère Error: datatype mismatch
-- insert into Post (id, name,text,author) values ('Victor', 'Blabla','Blabla',1); 