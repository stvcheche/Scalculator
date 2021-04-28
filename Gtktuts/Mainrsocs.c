/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include<string.h>
#include "Main.h"
#include <time.h>
#include "Sqlite/Sqlite.h"


/*Button input structure*/
/*Global variables*/
BtnInp *hind;

/*Add items*/
BtnInp* addVars(GtkWidget *btn, GtkWidget *inp, int index, BtnInp *heada) {
    BtnInp *newBtnip;
    newBtnip = (BtnInp*) malloc(sizeof (BtnInp));

    newBtnip->btn = btn;
    newBtnip->inp = inp;
    newBtnip->index = index;


    if (newBtnip == NULL) {
	printf("Error: Memory not available\n");

    } else {
	newBtnip->next = NULL;

	if (heada == NULL) {
	    heada = hind = newBtnip;

	} else {
	    hind->next = newBtnip;
	    hind = newBtnip;

	}

    }

    return heada;
}

/*Get by index*/
BtnInp * gtIndex(BtnInp *heada, int index) {
    BtnInp *i = heada;
    int y = 0;

    while (i != NULL) {
	if (y == index) {

	    break;
	} else {
	    i = i->next;
	    y += 1;
	}
    }
    return i;
}

/*Show data*/
void show_stacka(BtnInp *heada) {
    BtnInp *i = heada;

    while (i != NULL) {
	printf("Index: %i \n", i->index);
	i = i->next;
    }
}

/* Release memory */
void memrelease(BtnInp *heada) {
    BtnInp *i = heada;

    while (i != NULL) {
	i = i->next;
	free(i);
    }
}

/*Get the second number*/
char* gtSecndnum(const char *wsplit, int strt, int end) {
    int stlen = ((end - strt) + 1);
    char *sbstree = (char*) malloc(sizeof (char)*(stlen));
    strncpy(sbstree, (wsplit + strt), stlen);

    return sbstree;

}

/*Open database and create table*/
void createTbl() {
    sqlite3 *db;
    char *ErrMsg;
    int rc;
    char *sql;

    /*Create database if it does not exist*/
    rc = sqlite3_open("memdata.db", &db);
    if (rc) {
	fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	exit(1);

    } else {
    }


    /* Create table statement */
    sql = "CREATE TABLE IF NOT EXISTS mathdata(id INTEGER PRIMARY KEY AUTOINCREMENT,  "
	    "dates TEXT,  "
	    "mathres CHAR(50));";

    rc = sqlite3_exec(db, sql, NULL, NULL, &ErrMsg);
    if (rc != SQLITE_OK) {
	if (ErrMsg != NULL) {
	    fprintf(stderr, "SQL error: %s\n", ErrMsg);
	    sqlite3_free(ErrMsg);
	}
    }

    sqlite3_close(db);

}

/*Insert data*/
void insertData(const gchar *mathres) {
    int rc;
    sqlite3 *db;
    sqlite3_stmt *stmt;
    char *sql;
    const char *tail;
    char* dtatime = currTime();

    rc = sqlite3_open("memdata.db", &db);
    if (rc) {
	fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	sqlite3_close(db);
	exit(1);
    }

    sql = "INSERT INTO mathdata(dates, mathres)  VALUES (:datec, :mathdta);";
    rc = sqlite3_prepare(db, sql, strlen(sql), &stmt, &tail);

    sqlite3_bind_text(stmt, sqlite3_bind_parameter_index(stmt, ":datec"), dtatime, strlen(dtatime), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, sqlite3_bind_parameter_index(stmt, ":mathdta"), mathres, strlen(mathres), SQLITE_TRANSIENT);

    if (rc != SQLITE_OK) {
	fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    }

    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);

}

/*Get current date*/
char* currTime() {
    time_t now = time(0);
    localtime(&now);

    return ctime(&now);
}

/* Get data count */
void gtCount(int *counts) {
    int rc, i, ncols;
    sqlite3 *db;
    sqlite3_stmt *stmt;
    char *sql;
    const char *tail;

    rc = sqlite3_open("memdata.db", &db);
    if (rc) {
	fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	sqlite3_close(db);
	exit(1);
    }

    sql = "SELECT COUNT(*) AS zount FROM mathdata;";
    rc = sqlite3_prepare(db, sql, strlen(sql), &stmt, &tail);


    if (rc != SQLITE_OK) {
	fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    }

    rc = sqlite3_step(stmt);
    ncols = sqlite3_column_count(stmt);

    while (rc == SQLITE_ROW) {
	for (i = 0; i < ncols; i++) {
	    if (strcmp(sqlite3_column_name(stmt, i), "zount") == 0) {
		*counts = sqlite3_column_int(stmt, i);
	    }
	}
	rc = sqlite3_step(stmt);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

}

/* Get mem data */
char* gtData(int Idec) {
    int rc, i, ncols;
    sqlite3 *db;
    sqlite3_stmt *stmt;
    char *sql;
    const char *tail;
    const char *tmptxt;
    gchar *musk = "nada";

    rc = sqlite3_open("memdata.db", &db);
    if (rc) {
	fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	sqlite3_close(db);
	exit(1);
    }

    sql = "SELECT * FROM mathdata WHERE id=:idec;";
    rc = sqlite3_prepare(db, sql, strlen(sql), &stmt, &tail);
    sqlite3_bind_int(stmt, sqlite3_bind_parameter_index(stmt, ":idec"), Idec);

    if (rc != SQLITE_OK) {
	fprintf(stderr, "SQL error: %s\n", sqlite3_errmsg(db));
    }

    rc = sqlite3_step(stmt);
    ncols = sqlite3_column_count(stmt);

    while (rc == SQLITE_ROW) {
	for (i = 0; i < ncols; i++) {
	    if (strcmp(sqlite3_column_name(stmt, i), "mathres") == 0) {
		tmptxt = sqlite3_column_text(stmt, i);
		musk = g_strdup_printf("%s", tmptxt);

	    }
	}
	rc = sqlite3_step(stmt);
    }

    sqlite3_finalize(stmt);
    sqlite3_close(db);

    return musk;

}

/*Clear table data and reset sqlite sequence*/
void clearTbl() {
    sqlite3 *db;
    char *ErrMsg;
    int rc, drc;
    char *sql, *dsql;
    const char *tail;
    sqlite3_stmt *stmt;

    /*Create database if it does not exist*/
    rc = sqlite3_open("memdata.db", &db);
    if (rc) {
	fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
	exit(1);

    } else {
    }


    /* Create table statement */
    dsql = "DELETE  FROM mathdata;";
    drc = sqlite3_exec(db, dsql, NULL, NULL, &ErrMsg);

    sql = "UPDATE SQLITE_SEQUENCE SET SEQ = 0 WHERE NAME=:dbess;";

    rc = sqlite3_prepare(db, sql, strlen(sql), &stmt, &tail);
    sqlite3_bind_text(stmt, sqlite3_bind_parameter_index(stmt, ":dbess"), "mathdata", strlen("mathdata"), SQLITE_TRANSIENT);

    if (rc != SQLITE_OK) {
	if (ErrMsg != NULL) {
	    fprintf(stderr, "SQL error: %s\n", ErrMsg);
	    sqlite3_free(ErrMsg);
	}
    }

    rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db);

}