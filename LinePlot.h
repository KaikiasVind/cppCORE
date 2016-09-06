#ifndef LINEPLOT_H
#define LINEPLOT_H

#include "cppCORE_global.h"
#include <QString>
#include <QVector>

///Creates a line plot PNG image (needs Python in the path - and matplotlib extension).
class CPPCORESHARED_EXPORT LinePlot
{
public:
	LinePlot();

	void addLine(const QVector<double>& values, QString label = "");
	void setXValues(const QVector<double>& xvalues);

	void setXLabel(QString xlabel);
	void setYLabel(QString ylabel);
	void setYRange(double ymin, double ymax);

	void store(QString filename);

protected:
	//line representation
	struct PlotLine
	{
		PlotLine();
		PlotLine(const QVector<double>& v, QString l);
		QVector<double> values;
		QString label;
	};

	//variables to store the plot data
	QVector<PlotLine> lines_;
	QVector<double> xvalues_;
	QString xlabel_;
	QString ylabel_;
	double ymin_;
	double ymax_;

	//variables to store the meta data
	bool yrange_set_;
};

#endif // LINEPLOT_H
