#include <stdio.h>
#include <stdlib.h>
#include <sqlite3.h>
#include <string.h>

static int callback(void *data, int argc, char **argv, char **azColName)
{
    int i;
    fprintf(stdout, "%s: ", (const char *)data);

    for (i = 0; i < argc; i++)
    {
        printf("%s : %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    
    printf("\n");
    return 0;
}

int main(int argc, char *argv[])
{
    sqlite3 *db;
    char *zErrMsg = 0;
    int rc;
    char *sql1;
    char sql2[10];
    const char *data = "Callback function for: ";

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
    sql1 = "SELECT AGE, SALARY from COMPANY where ID = ";
    strcpy(sql2, argv[1]);
    //printf("%s\n", sql2);

    char * sql = (char *) malloc( sizeof(sql1) + sizeof(sql2) );
    strcpy(sql, sql1);
    strcat(sql, sql2);

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
    return 0;
}