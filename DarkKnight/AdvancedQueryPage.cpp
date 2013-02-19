#include "AdvancedQueryPage.h"
#include <QueryParser.h>
#include <QFileDialog>
#include <QTextStream>

AdvancedQueryPage::AdvancedQueryPage(QWidget *parent)
	: QWizardPage(parent)
	, ui(new Ui::AdvancedQueryPage)
{
	ui->setupUi(this);
	connect(ui->queryTextEdit, SIGNAL(textChanged()), this, SIGNAL(completeChanged()));
	connect(ui->browseBttn, SIGNAL(clicked()), this, SLOT(loadFromFile()));
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

void AdvancedQueryPage::loadFromFile()
{
	QString filePath = QFileDialog::getOpenFileName(this, tr("Select query file"), QDir::homePath(), tr("CGSQL Query file (*.cgsql)"));
	if(filePath.isEmpty())
		return;
	QFile queryFile(filePath);
	if(queryFile.open(QIODevice::ReadOnly))
	{
		QTextStream queryStream(&queryFile);
		const QString queryText = queryStream.readAll();
		if(!queryText.isEmpty())
			ui->queryTextEdit->setText(queryText);
	}
}