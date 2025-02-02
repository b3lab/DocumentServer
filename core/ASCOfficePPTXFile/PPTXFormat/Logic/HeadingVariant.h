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
#ifndef PPTX_LOGIC_HEADING_VARIANT_INCLUDE_H_
#define PPTX_LOGIC_HEADING_VARIANT_INCLUDE_H_

#include "./../WrapperWritingElement.h"
#include "./../Limit/VariantType.h"

namespace PPTX
{
	namespace Logic
	{

		class HeadingVariant : public WrapperWritingElement
		{
		public:
			PPTX_LOGIC_BASE(HeadingVariant)

		public:
			virtual void fromXML(XmlUtils::CXmlNode& node)
			{
				XmlUtils::CXmlNode oNode = node.ReadNodeNoNS(_T("i4"));
				if (oNode.IsValid())
				{
					m_type		= L"i4";
					m_iContent	= oNode.GetTextExt();
				}
				else
				{
					m_type		 = L"lpstr";
					m_strContent =	 node.ReadNodeNoNS(_T("lpstr")).GetTextExt();
				}
			}
			virtual std::wstring toXML() const
			{
				if (m_type.IsInit() && (m_type->get() == _T("i4")))
				{
                    return _T("<vt:variant><vt:i4>") + std::to_wstring(*m_iContent) + _T("</vt:i4></vt:variant>");
				}
				return _T("<vt:variant><vt:lpstr>") + *m_strContent + _T("</vt:lpstr></vt:variant>");
			}
			virtual void toXmlWriter(NSBinPptxRW::CXmlWriter* pWriter) const
			{
				pWriter->StartNode(_T("vt:variant"));
				pWriter->EndAttributes();

				if (m_type.IsInit() && (m_type->get() == _T("i4")))
				{
					pWriter->WriteNodeValue(_T("vt:i4"), *m_iContent);
				}
				else
				{
					pWriter->WriteNodeValue(_T("vt:lpstr"), *m_strContent);
				}

				pWriter->EndNode(_T("vt:variant"));
			}

		public:
			nullable_limit<Limit::VariantType>		m_type;
			nullable_string							m_strContent;
			nullable_int							m_iContent;
		protected:
			virtual void FillParentPointersForChilds(){};
		};
	} // namespace Logic
} // namespace PPTX

#endif // PPTX_LOGIC_HEADING_VARIANT_INCLUDE_H_
