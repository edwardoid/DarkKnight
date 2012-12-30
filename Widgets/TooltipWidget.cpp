#include "TooltipWidget.h"


TooltipWidget::TooltipWidget(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}


TooltipWidget::~TooltipWidget(void)
{
}

void TooltipWidget::setPixmap( const QPixmap& pixmap )
{
	ui.thumbLabel->setPixmap(pixmap);
	ui.thumbLabel->setText(QString::null);
}

void TooltipWidget::setSquare(const QString& square)
{
	ui.thumbLabel->setPixmap(QPixmap());
	ui.thumbLabel->setText(square);
}

void TooltipWidget::setText(const QString& text)
{
	ui.infoLabel->setText(text);
}
