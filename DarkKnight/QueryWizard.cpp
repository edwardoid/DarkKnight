#include "QueryWizard.h"
#include "ui_QueryWizard.h"
#include <QMessageBox>
#include <Framework.h>
#include <DataStore.h>

Q_DECLARE_METATYPE(const DataStore*)

QueryWizard::QueryWizard(QWidget* parent /* = NULL */)
	: QWizard(parent)
	, ui(new Ui::QueryWizard)
{
	ui->setupUi(this);
	connect(ui->storesListWidget, SIGNAL(currentItemChanged(QListWidgetItem*, QListWidgetItem*)),
			this, SLOT(currentStoreChanged(QListWidgetItem*, QListWidgetItem*)));

	populateDataStores();
}

void QueryWizard::populateDataStores()
{
	Framework* fw = Framework::instance();
	const DataStoresList& dataStores = fw->dataStores();
	if(dataStores.isEmpty())
	{
		QMessageBox::critical(this, tr("No stores loaded"), tr("Can not create query, because no stores are loaded."));
		emit finished(QDialog::Rejected);
		return;
	}
	foreach(const DataStore* ds, dataStores)
	{
		QListWidgetItem* item = new QListWidgetItem(ui->storesListWidget);
		item->setText(ds->name());
		item->setData(Qt::UserRole, QVariant::fromValue(ds));
		ui->storesListWidget->addItem(item);
	}
	ui->storesListWidget->setCurrentRow(0);
}

QueryWizard::~QueryWizard(void)
{
}

void QueryWizard::currentStoreChanged( QListWidgetItem* current, QListWidgetItem* )
{
	const DataStore* store = current->data(Qt::UserRole).value<const DataStore*>();
	if(store)
	{
		ui->infoLabel->setText(store->author());
	}
}
