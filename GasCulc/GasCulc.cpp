#include "GasCulc.h"

#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QAction>

GasCulc::GasCulc()
{
    QLabel* l = new QLabel( this );
    l->setText( "Hello World!" );
    setCentralWidget( l );
    QAction* a = new QAction(this);
    a->setText( "Quit" );
    connect(a, SIGNAL(triggered()), SLOT(close()) );
    menuBar()->addMenu( "File" )->addAction( a );
}

GasCulc::~GasCulc()
{}

#include "GasCulc.moc"
