#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

typedef struct {
    int id;
    char name[50];
} Company;

static int callback(void *data, int argc, char **argv, char **azColName)
{
    int i;
    //fprintf(stdout, "%s: ", (const char *)data);
    Company *c = (Company *)data;
    c->id = atoi(argv[0]);

    for (i = 0; i < argc; i++)
    {
        printf("%s : %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
        // écrire les données en mémoire via le pointeur *data
    }
    
    
    printf("\n");
    return 0;
}

int main(int argc, char *argv[])
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql;

    Company c;
    Company *data = &c;

    /* Open database */
    rc = sqlite3_open("test.db", &db);

    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return (0);
    }
    else
    {
        fprintf(stderr, "Opened database successfully\n");
    }

    /* Create SQL statement */
    sql = "SELECT ID, AGE, SALARY from COMPANY where ID = 4";

    /* Execute SQL statement */
    rc = sqlite3_exec(db, sql, callback, (void *)data, &zErrMsg);

    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    }
    else
    {
        fprintf(stdout, "Operation done successfully\n");
    }
    sqlite3_close(db);

    printf("%d\n", c.id);

    return 0;
}