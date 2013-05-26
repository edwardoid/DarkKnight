#include "QueryEditor.h"
#include "ui_QueryEditor.h"
#include <Keywords.h>

QueryEditor::QueryEditor( QWidget* parent /*= NULL*/ )
	: QDialog(parent)
	, ui(new Ui::QueryEditor)
{
	ui->setupUi(this);
}

QueryEditor::~QueryEditor()
{

}