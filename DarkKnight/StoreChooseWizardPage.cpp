#include "StoreChooseWizardPage.h"
#include <QListWidgetItem>
#include <QMessageBox>
#include <Framework.h>
#include <DataStore.h>

Q_DECLARE_METATYPE(quint32)

StoreChooseWizardPage::StoreChooseWizardPage(QWidget *parent)
	: QWizardPage(parent)
{
	ui.setupUi(this);

	connect(ui.storesListWidget, SIGNAL(currentItemChanged(QListWidgetItem*, QListWidgetItem*)),
		this, SLOT(currentStoreChanged(QListWidgetItem*, QListWidgetItem*)));
	registerField("store*", this, "currentStore", SIGNAL(storeChanged(quint32)));
}

StoreChooseWizardPage::~StoreChooseWizardPage()
{

}

void StoreChooseWizardPage::initWithFramework(Framework* fw)
{
	FrameworkUser::initWithFramework(fw);
	populateDataStores();
}

quint32 StoreChooseWizardPage::currentStore() const
{
	return m_currentStore;
}
void StoreChooseWizardPage::populateDataStores()
{
	const Framework* fw = framework();
	const DataStoresList& dataStores = fw->dataStores();
	if(dataStores.isEmpty())
	{
		QMessageBox::critical(this, tr("No stores loaded"), tr("Can not create query, because no stores are loaded."));
		return;
	}
	foreach(const DataStore* ds, dataStores)
	{
		QListWidgetItem* item = new QListWidgetItem(ui.storesListWidget);
		item->setText(ds->name());
		item->setData(Qt::UserRole, QVariant::fromValue(ds->id()));
		ui.storesListWidget->addItem(item);
	}
	ui.storesListWidget->setCurrentRow(0);
}


void StoreChooseWizardPage::currentStoreChanged( QListWidgetItem* current, QListWidgetItem* )
{
	if (!current) return;
	quint32 id = current->data(Qt::UserRole).value<quint32>();
	const DataStore* store = framework()->dataStoreById(id);
	if(store)
	{
		ui.infoLabel->setText(store->author());
		m_currentStore = id;
		emit storeChanged(m_currentStore);
	}
}