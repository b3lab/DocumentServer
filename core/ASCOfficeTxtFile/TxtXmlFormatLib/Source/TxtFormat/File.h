﻿/*
 * (c) Copyright Ascensio System SIA 2010-2019
 *
 * This program is a free software product. You can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License (AGPL)
 * version 3 as published by the Free Software Foundation. In accordance with
 * Section 7(a) of the GNU AGPL its Section 15 shall be amended to the effect
 * that Ascensio System SIA expressly excludes the warranty of non-infringement
 * of any third-party rights.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR  PURPOSE. For
 * details, see the GNU AGPL at: http://www.gnu.org/licenses/agpl-3.0.html
 *
 * You can contact Ascensio System SIA at 20A-12 Ernesta Birznieka-Upisha
 * street, Riga, Latvia, EU, LV-1050.
 *
 * The  interactive user interfaces in modified source and object code versions
 * of the Program must display Appropriate Legal Notices, as required under
 * Section 5 of the GNU AGPL version 3.
 *
 * Pursuant to Section 7(b) of the License you must retain the original Product
 * logo when distributing the program. Pursuant to Section 7(e) we decline to
 * grant you any rights under trademark law for use of our trademarks.
 *
 * All the Product's GUI elements, including illustrations and icon sets, as
 * well as technical writing content are licensed under the terms of the
 * Creative Commons Attribution-ShareAlike 4.0 International. See the License
 * terms at http://creativecommons.org/licenses/by-sa/4.0/legalcode
 *
 */
#pragma once
#ifndef TXT_FILE_INCLUDE_H_
#define TXT_FILE_INCLUDE_H_

#include <vector>
#include <string>

namespace Txt
{
	class File
	{
	public:
		File();
		~File();

        void read			(const std::wstring& filename);
        void read			(const std::wstring& filename, int code_page);
		
        void write			(const std::wstring& filename) const;
		
        void writeCodePage	(const std::wstring& filename, int code_page) const;
        void writeUtf8		(const std::wstring& filename) const;
        void writeUnicode	(const std::wstring& filename) const;
        void writeBigEndian	(const std::wstring& filename) const;
        void writeAnsi		(const std::wstring& filename) const;
		
        const bool isValid	(const std::wstring& filename) const;
		
        std::vector<std::wstring>	m_listContent;			//unicode  (ранее было utf8)
		int							m_listContentSize;		//для вывода процентов конвертации
		int							m_nEncoding;
	private:
        void correctUnicode(std::vector<std::wstring>& oList);
		bool IsUnicodeSymbol( wchar_t symbol );
	};
} // namespace Txt

#endif // TXT_FILE_INCLUDE_H_
