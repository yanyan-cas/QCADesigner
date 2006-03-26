//////////////////////////////////////////////////////////
// QCADesigner                                          //
// Copyright 2002 Konrad Walus                          //
// All Rights Reserved                                  //
// Author: Konrad Walus                                 //
// Email: qcadesigner@gmail.com                         //
// WEB: http://qcadesigner.ca/                          //
//////////////////////////////////////////////////////////
//******************************************************//
//*********** PLEASE DO NOT REFORMAT THIS CODE *********//
//******************************************************//
// If your editor wraps long lines disable it or don't  //
// save the core files that way. Any independent files  //
// you generate format as you wish.                     //
//////////////////////////////////////////////////////////
// Please use complete names in variables and fucntions //
// This will reduce ramp up time for new people trying  //
// to contribute to the project.                        //
//////////////////////////////////////////////////////////
// This file was contributed by Gabriel Schulhof        //
// (schulhof@atips.ca).                                 //
//////////////////////////////////////////////////////////
// Contents:                                            //
//                                                      //
// Header for the print dialog. This is a basic print   //
// dialog derived from GtkDialog. It is a dialog box    //
// with 3 property pages and a facility for adding      //
// more.                                                //
//                                                      //
//////////////////////////////////////////////////////////

#ifndef _OBJECTS_QCADPrintDialog_H_
#define _OBJECTS_QCADPrintDialog_H_

#include <gtk/gtk.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef enum _QCADPrintDialogUnits QCADPrintDialogUnits ;

typedef struct _print_OP             print_OP ;
typedef struct _QCADPrintDialog      QCADPrintDialog ;
typedef struct _QCADPrintDialogClass QCADPrintDialogClass ;

enum _QCADPrintDialogUnits
  {
  PD_UNITS_CENTIS,
  PD_UNITS_INCHES,
  PD_UNITS_POINTS
  } ;

struct _print_OP
  {
  double dPaperCX ;
  double dPaperCY ;
  double dLMargin ;
  double dTMargin ;
  double dRMargin ;
  double dBMargin ;
  gboolean bPrintFile ;
  gboolean bPortrait ;
  char *pszPrintString ;
  } ;

struct _QCADPrintDialog
  {
  GtkDialog dlg ;
  } ;

struct _QCADPrintDialogClass
  {
  GtkDialogClass parent_class ;
  void (*changed) (QCADPrintDialog *pd, gpointer data) ;
  void (*units_changed) (QCADPrintDialog *pd, gpointer data) ;
  void (*preview) (QCADPrintDialog *pd, gpointer data) ;
  } ;

GType qcad_print_dialog_get_type () ;

// Public function
GtkWidget *qcad_print_dialog_new (print_OP *pPO) ;
void qcad_print_dialog_add_page (QCADPrintDialog *pd, GtkWidget *contents, char *pszLbl) ;
void qcad_print_dialog_get_options (QCADPrintDialog *pd, print_OP *pPO) ;
double qcad_print_dialog_to_current_units (QCADPrintDialog *pd, double dPoints) ;
double qcad_print_dialog_from_current_units (QCADPrintDialog *pd, double dPoints) ;
char *qcad_print_dialog_get_units_short_string (QCADPrintDialog *pd) ;
QCADPrintDialogUnits qcad_print_dialog_get_units (QCADPrintDialog *pd) ;

#define QCAD_TYPE_STRING_PRINT_DIALOG "QCADPrintDialog"
#define QCAD_TYPE_PRINT_DIALOG (qcad_print_dialog_get_type ())
#define QCAD_PRINT_DIALOG(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), QCAD_TYPE_PRINT_DIALOG, QCADPrintDialog))
#define QCAD_IS_PRINT_DIALOG(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), QCAD_TYPE_PRINT_DIALOG))
#define QCAD_PRINT_DIALOG_GET_CLASS(object) (G_TYPE_INSTANCE_GET_CLASS  ((object), QCAD_TYPE_PRINT_DIALOG, QCADPrintDialogClass))
#define QCAD_PRINT_DIALOG_CLASS(klass)      (G_TYPE_CHECK_CLASS_CAST    ((klass),  QCAD_TYPE_PRINT_DIALOG, QCADPrintDialogClass))
#define QCAD_IS_PRINT_DIALOG_CLASS(klass)   (G_TYPE_CHECK_CLASS_TYPE    ((klass),  QCAD_TYPE_PRINT_DIALOG))

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _OBJECTS_QCADPrintDialog_H_ */
