#include "AdvancedQueryPage.h"
#include <QueryParser.h>

AdvancedQueryPage::AdvancedQueryPage(QWidget *parent)
	: QWizardPage(parent)
	, ui(new Ui::AdvancedQueryPage)
{
	ui->setupUi(this);
	connect(ui->queryTextEdit, SIGNAL(textChanged()), this, SIGNAL(completeChanged()));
	registerField("query*", ui->queryTextEdit, "plainText", "textChanged");
}

AdvancedQueryPage::~AdvancedQueryPage()
{

}

bool AdvancedQueryPage::isComplete() const
{
	CGSQL_NS::QueryParser parser;
	return NULL != parser.parse(ui->queryTextEdit->toPlainText().toStdString());
}
