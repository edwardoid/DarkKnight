#include "QueryEditor.h"
#include "ui_QueryEditor.h"
#include "CGSQLSyntaxHighlighter.h"
#include <Keywords.h>

QueryEditor::QueryEditor( QWidget* parent /*= NULL*/ )
	: QDialog(parent)
	, ui(new Ui::QueryEditor)
{
	ui->setupUi(this);
	m_highlighter = new class CGSQLSyntaxHighlighter(ui->textEdit);
	m_highlighter->setDocument(ui->textEdit->document());
}

QueryEditor::~QueryEditor()
{

}