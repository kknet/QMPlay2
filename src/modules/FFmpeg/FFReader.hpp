/*
	QMPlay2 is a video and audio player.
	Copyright (C) 2010-2017  Błażej Szczygieł

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU Lesser General Public License as published
	by the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU Lesser General Public License for more details.

	You should have received a copy of the GNU Lesser General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <Reader.hpp>

#include <OpenThr.hpp>

struct AVIOContext;

class FFReader : public Reader
{
public:
	FFReader();
private:
	bool readyRead() const override final;
	bool canSeek() const override final;

	bool seek(qint64) override final;
	QByteArray read(qint64) override final;
	void pause() override final;
	bool atEnd() const override final;
	void abort() override final;

	qint64 size() const override final;
	qint64 pos() const override final;
	QString name() const override final;

	bool open() override final;

	/**/

	~FFReader() final;

	AVIOContext *avioCtx;
	bool paused, canRead;
	QSharedPointer<AbortContext> abortCtx;
};
