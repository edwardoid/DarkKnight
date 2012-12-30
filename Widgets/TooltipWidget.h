#ifndef TOOLTIPWIDGET_H
#define TOOLTIPWIDGET_H

#include <QWidget>
#include "ui_TooltipWidget.h"

class TooltipWidget :
	public QWidget
{
	Q_OBJECT
public:
	explicit TooltipWidget(QWidget* parent = NULL);
	virtual ~TooltipWidget();
	void setPixmap(const QPixmap& pixmap);
	void setSquare(const QString& square);
	void setText(const QString& text);
private:
	Ui::TooltipWidget ui;
};

#endif // TOOLTIPWIDGET_H