/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include "Main.h"

/*Initialize functions*/
void setText(GtkWidget*, BtnInp*);
void freeMem(GtkWidget*, BtnInp*);
gboolean zemp(GtkWidget*, GdkEventKey*, gpointer);

void numSwitch(GtkWidget*, const gchar*);

/*Global variables*/
Dvarsecs *dvariables;
BtnInp *btninpstuct;

gchar *numlnmod;
gchar *numlnmoda;
gchar *nummod;
int lupnum;

/*Main UI*/
GtkWidget* retVbox() {
    GtkWidget *vbox, *numpadgrid, *hbox, *fnbox;
    lupnum = 1;

    /*Initialize structures*/
    dvariables = (Dvarsecs*) malloc(sizeof (Dvarsecs));
    dvariables->fstvals = "nada";
    dvariables->operands = "nada";
    dvariables->secndval = "nada";
    dvariables->mresult = "nada";
    dvariables->predisx = "nada";

    /*Create entry*/
    GtkWidget *globentry = gtk_entry_new();
    gtk_widget_set_name(globentry, "calcentry");
    GtkStyleContext *entryctx = gtk_widget_get_style_context(GTK_WIDGET(globentry));
    gtk_style_context_add_class(entryctx, "lblclass");
    g_signal_connect(globentry, "key_press_event", G_CALLBACK(zemp), NULL);


    /*Number-pads*/
    numpadgrid = gtk_grid_new();
    gtk_widget_set_name(numpadgrid, "numpadidec");

    /*Stretch grid to height and width*/
    /*gtk_grid_set_column_homogeneous(GTK_GRID(numpadgrid), TRUE);
     *gtk_grid_set_row_homogeneous(GTK_GRID(numpadgrid), TRUE);*/

    int ghas = 0;
    int ghasa = 0;

    for (int mx = 0; mx < 3; mx++) {
	for (int mxa = 0; mxa < 3; mxa++) {
	    ghas += 1;

	    gchar *castint = g_strdup_printf("%d", ghas);
	    GtkWidget *numpad = gtk_button_new_with_label(castint);
	    gtk_widget_set_name(numpad, "numpads");
	    gtk_grid_attach(GTK_GRID(numpadgrid), numpad, mxa, mx, 1, 1);
	    g_free(castint);

	    btninpstuct = addVars(numpad, globentry, ghasa, btninpstuct);
	    g_signal_connect(numpad, "clicked", G_CALLBACK(setText), gtIndex(btninpstuct, ghasa));
	    gtk_widget_set_can_focus(numpad, FALSE);

	    ghasa += 1;
	}
    }


    /*Zero and equals button*/
    GtkWidget *zerobtn = gtk_button_new_with_label("0");
    GtkWidget *peroid = gtk_button_new_with_label(".");
    GtkWidget *equalbtn = gtk_button_new_with_label("=");

    gtk_widget_set_name(zerobtn, "numpadsa");
    gtk_widget_set_name(peroid, "numpadsa");
    gtk_widget_set_name(equalbtn, "numpadsa");

    gtk_widget_set_can_focus(zerobtn, FALSE);
    gtk_widget_set_can_focus(peroid, FALSE);
    gtk_widget_set_can_focus(equalbtn, FALSE);

    gtk_grid_attach(GTK_GRID(numpadgrid), zerobtn, 0, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(numpadgrid), peroid, 1, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(numpadgrid), equalbtn, 2, 3, 1, 1);


    btninpstuct = addVars(zerobtn, globentry, ghasa, btninpstuct);
    g_signal_connect(zerobtn, "clicked", G_CALLBACK(setText), gtIndex(btninpstuct, ghasa));

    ghasa += 1;
    btninpstuct = addVars(peroid, globentry, ghasa, btninpstuct);
    g_signal_connect(peroid, "clicked", G_CALLBACK(setText), gtIndex(btninpstuct, ghasa));

    ghasa += 1;
    btninpstuct = addVars(equalbtn, globentry, ghasa, btninpstuct);
    g_signal_connect(equalbtn, "clicked", G_CALLBACK(setText), gtIndex(btninpstuct, ghasa));


    /*Bottom misc buttons*/
    hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    char *names[] = {"Clr", "Memsv", "Memgt", "AC"};


    for (int m = 0; m < 4; m++) {
	GtkWidget *miscbtn = gtk_button_new_with_label(names[m]);
	gtk_widget_set_name(miscbtn, "numpadsb");
	gtk_widget_set_can_focus(miscbtn, FALSE);
	gtk_box_pack_start(GTK_BOX(hbox), miscbtn, TRUE, TRUE, 0);

	ghasa += 1;
	btninpstuct = addVars(miscbtn, globentry, ghasa, btninpstuct);
	g_signal_connect(miscbtn, "clicked", G_CALLBACK(setText), gtIndex(btninpstuct, ghasa));

    }

    /*Function buttons*/
    fnbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    char *symbols[] = {"+", "-", "/", "*"};

    for (int m = 0; m < 4; m++) {
	GtkWidget *fncbtn = gtk_button_new_with_label(symbols[m]);
	gtk_widget_set_name(fncbtn, "numpadsc");
	gtk_widget_set_can_focus(fncbtn, FALSE);
	gtk_box_pack_start(GTK_BOX(fnbox), fncbtn, TRUE, TRUE, 0);

	ghasa += 1;
	btninpstuct = addVars(fncbtn, globentry, ghasa, btninpstuct);
	g_signal_connect(fncbtn, "clicked", G_CALLBACK(setText), gtIndex(btninpstuct, ghasa));

    }

    gtk_grid_attach(GTK_GRID(numpadgrid), hbox, 0, 4, 3, 1);
    gtk_grid_attach(GTK_GRID(numpadgrid), fnbox, 5, 0, 1, 5);

    /*Create Vbox container*/
    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_widget_set_name(vbox, "prntvbox");

    /* Add button to window */
    gtk_box_pack_start(GTK_BOX(vbox), globentry, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), numpadgrid, TRUE, TRUE, 0);

    return vbox;
}

/*Entry set text action listener*/
gboolean zemp(GtkWidget *entry, GdkEventKey *event, gpointer userdata) {

    const gchar *num = event->string;
    numSwitch(entry, num);

    return TRUE;

}

/*Button click action listeners*/
void setText(GtkWidget *wdget, BtnInp *btninpstuct) {
    GtkWidget *btn = btninpstuct-> btn;
    GtkWidget *entry = btninpstuct-> inp;
    const gchar *num = gtk_button_get_label(GTK_BUTTON(btn));

    if (strcmp(num, "Clr") == 0) {
	/*Clear input*/
	const gchar *prnumln = gtk_entry_get_text(GTK_ENTRY(entry));
	gint pos = strlen(prnumln);

	gtk_editable_delete_text(GTK_EDITABLE(entry), 0, pos);
	dvariables->fstvals = "nada";
	dvariables->secndval = "nada";
	dvariables->operands = "nada";
	dvariables->mresult = "nada";
	dvariables->predisx = "nada";

    } else if (strcmp(num, "Memsv") == 0) {
	const gchar *prnumln = gtk_entry_get_text(GTK_ENTRY(entry));
	insertData(prnumln);

    } else if (strcmp(num, "Memgt") == 0) {
	int counts = 1;
	gchar *memtxt = gtData(lupnum);

	if (strcmp(memtxt, "nada") != 0) {
	    /*Set text*/
	    gtk_entry_set_text(GTK_ENTRY(entry), memtxt);

	    /*Move cursor to the end*/
	    const gchar *numln = gtk_entry_get_text(GTK_ENTRY(entry));
	    gtk_editable_set_position(GTK_EDITABLE(entry), strlen(numln));
	    free(memtxt);

	    gtCount(&counts);

	    if (lupnum == counts) {
		lupnum = 1;
	    } else {
		lupnum += 1;
	    }
	}

    } else if (strcmp(num, "AC") == 0) {
	/*Clear table and reset sqlite sequence*/
	clearTbl();

	/*Clear input*/
	const gchar *prnumln = gtk_entry_get_text(GTK_ENTRY(entry));
	gint pos = strlen(prnumln);

	gtk_editable_delete_text(GTK_EDITABLE(entry), 0, pos);
	dvariables->fstvals = "nada";
	dvariables->secndval = "nada";
	dvariables->operands = "nada";
	dvariables->mresult = "nada";

    } else {
	/*Set input*/
	numSwitch(entry, num);
    }
}

/*Key entry values switch*/
void numSwitch(GtkWidget *entry, const gchar *num) {
    const char *nuks = "nada";

    if (strcmp(num, "0") == 0 || strcmp(num, "1") == 0 || strcmp(num, "2") == 0 || strcmp(num, "3") == 0 || strcmp(num, "4") == 0 ||
	strcmp(num, "5") == 0 || strcmp(num, "6") == 0 || strcmp(num, "7") == 0 || strcmp(num, "8") == 0 || strcmp(num, "9") == 0) {
	/*Set the next text insert point*/
	const gchar *prnumln = gtk_entry_get_text(GTK_ENTRY(entry));
	gint tmp_pos = strlen(prnumln);

	if (strcmp(dvariables->mresult, nuks) == 0) {
	    gtk_editable_insert_text(GTK_EDITABLE(entry), num, -1, &tmp_pos);
	}

	/*Move cursor to the end*/
	const char *numln = gtk_entry_get_text(GTK_ENTRY(entry));
	gtk_editable_set_position(GTK_EDITABLE(entry), strlen(numln));

	if (strcmp(dvariables->operands, nuks) == 0 && strcmp(dvariables->secndval, nuks) == 0 && strcmp(dvariables->mresult, nuks) == 0) {
	    numlnmod = g_strdup_printf("%s", numln);
	    dvariables->fstvals = numlnmod;

	} else if (strcmp(dvariables->operands, nuks) != 0 && strcmp(dvariables->mresult, nuks) == 0) {
	    char *scnum = gtSecndnum(numln, strlen(dvariables->fstvals) + 1, strlen(numln));

	    numlnmoda = g_strdup_printf("%s", scnum);
	    dvariables->secndval = numlnmoda;
	    free(scnum);

	}
    } else if (strcmp(num, ".") == 0) {
	/*Set the next text insert point*/
	const gchar *prnumln = gtk_entry_get_text(GTK_ENTRY(entry));
	gint tmp_pos = strlen(prnumln);

	if (strcmp(dvariables->fstvals, nuks) != 0 && strcmp(dvariables->secndval, nuks) == 0) {
	    if (strcmp(dvariables->mresult, nuks) == 0 && strcmp(dvariables->predisx, "a") != 0) {
		gtk_editable_insert_text(GTK_EDITABLE(entry), num, -1, &tmp_pos);

	    }
	    dvariables->predisx = "a";

	} else if (strcmp(dvariables->fstvals, nuks) != 0 && strcmp(dvariables->secndval, nuks) != 0) {
	    if (strcmp(dvariables->mresult, nuks) == 0 && strcmp(dvariables->predisx, "ab") != 0) {
		gtk_editable_insert_text(GTK_EDITABLE(entry), num, -1, &tmp_pos);

	    }
	    dvariables->predisx = "ab";
	}

	/*Move cursor to the end*/
	const char *numln = gtk_entry_get_text(GTK_ENTRY(entry));
	gtk_editable_set_position(GTK_EDITABLE(entry), strlen(numln));

    } else if (strcmp(num, "+") == 0 || strcmp(num, "-") == 0 || strcmp(num, "/") == 0 || strcmp(num, "*") == 0) {
	if (strcmp(dvariables->operands, nuks) == 0 && strcmp(dvariables->secndval, nuks) == 0 && strcmp(dvariables->mresult, nuks) == 0) {
	    /*Set the next text insert point*/
	    const gchar *prnumln = gtk_entry_get_text(GTK_ENTRY(entry));
	    gint tmp_pos = strlen(prnumln);
	    gtk_editable_insert_text(GTK_EDITABLE(entry), num, -1, &tmp_pos);

	    /*Move cursor to the end*/
	    const gchar *numln = gtk_entry_get_text(GTK_ENTRY(entry));
	    gtk_editable_set_position(GTK_EDITABLE(entry), strlen(numln));

	    nummod = g_strdup_printf("%s", num);
	    dvariables->operands = nummod;

	}
    } else if (strcmp(num, "=") == 0) {
	if (strcmp(dvariables->fstvals, nuks) != 0 && strcmp(dvariables->operands, nuks) != 0 && strcmp(dvariables->secndval, nuks) != 0 &&
	strcmp(dvariables->mresult, nuks) == 0) {
	    /*Insert text*/
	    const gchar *prnumln = gtk_entry_get_text(GTK_ENTRY(entry));
	    gint tmp_pos = strlen(prnumln);
	    gtk_editable_insert_text(GTK_EDITABLE(entry), num, -1, &tmp_pos);

	    /*Insert answer*/
	    float answer = 0;
	    if (strcmp(dvariables->operands, "+") == 0) {
		answer = atof(dvariables->fstvals) + atof(dvariables->secndval);
	    } else if (strcmp(dvariables->operands, "-") == 0) {
		answer = atof(dvariables->fstvals) - atof(dvariables->secndval);
	    } else if (strcmp(dvariables->operands, "/") == 0) {
		answer = atof(dvariables->fstvals) / atof(dvariables->secndval);
	    } else if (strcmp(dvariables->operands, "*") == 0) {
		answer = atof(dvariables->fstvals) * atof(dvariables->secndval);
	    }

	    /*Insert answer*/
	    gchar *answerch = g_strdup_printf("%.2f", answer);
	    gtk_editable_insert_text(GTK_EDITABLE(entry), answerch, -1, &tmp_pos);
	    dvariables->mresult = answerch;

	    /*Move cursor to the end*/
	    const gchar *numln = gtk_entry_get_text(GTK_ENTRY(entry));
	    gtk_editable_set_position(GTK_EDITABLE(entry), strlen(numln));
	    free(answerch);

	}
    }

}

/*Free memory*/
void freemainMem() {
    /*Free memory*/
    free(numlnmod);
    free(numlnmoda);
    free(nummod);

    free(dvariables);
    memrelease(btninpstuct);

}