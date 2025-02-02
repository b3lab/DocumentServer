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
#ifndef OOX_DXFS_FILE_INCLUDE_H_
#define OOX_DXFS_FILE_INCLUDE_H_

#include "../CommonInclude.h"

#include "Borders.h"
#include "Fills.h"
#include "Fonts.h"
#include "NumFmts.h"
#include "Xfs.h"

namespace OOX
{
	namespace Spreadsheet
	{
		class CDxf : public WritingElement
		{
		public:
			WritingElement_AdditionConstructors(CDxf)
			CDxf()
			{
			}
			virtual ~CDxf()
			{
			}
			virtual void fromXML(XmlUtils::CXmlNode& node)
			{
			}
            virtual std::wstring      toXML() const
			{
				return _T("");
			}
			virtual void toXML(NSStringUtils::CStringBuilder& writer) const
			{
				toXML2(writer, L"dxf");
			}
			void toXML2(NSStringUtils::CStringBuilder& writer, const std::wstring &node_name) const
			{
				writer.WriteString(L"<" + node_name + L">");
				if(m_oFont.IsInit())
					m_oFont->toXML(writer);
				if(m_oNumFmt.IsInit())
					m_oNumFmt->toXML(writer);
				if(m_oFill.IsInit())
					m_oFill->toXML(writer);
				if(m_oAlignment.IsInit())
					m_oAlignment->toXML(writer);
				if(m_oBorder.IsInit())
					m_oBorder->toXML(writer);
				if(m_oProtection.IsInit())
					m_oProtection->toXML(writer);
				writer.WriteString(L"</" + node_name + L">");
			}

			virtual void fromXML(XmlUtils::CXmlLiteReader& oReader)
			{
				ReadAttributes( oReader );

				if ( oReader.IsEmptyNode() )
					return;

				int nCurDepth = oReader.GetDepth();
				while( oReader.ReadNextSiblingNode( nCurDepth ) )
				{
					std::wstring sName = XmlUtils::GetNameNoNS(oReader.GetName());

					if ( _T("alignment") == sName )
						m_oAlignment = oReader;
					else if ( _T("border") == sName )
						m_oBorder = oReader;
					else if ( _T("fill") == sName )
						m_oFill = oReader;
					else if ( _T("font") == sName )
						m_oFont = oReader;
					else if ( _T("numFmt") == sName )
						m_oNumFmt = oReader;
					else if ( _T("protection") == sName )
						m_oProtection = oReader;
				}
			}

			virtual EElementType getType () const
			{
				return et_x_Dxf;
			}

		private:
			void ReadAttributes(XmlUtils::CXmlLiteReader& oReader)
			{
			}
		public:
			nullable<CAligment>		m_oAlignment;
			nullable<CBorder>		m_oBorder;
			nullable<CFill>			m_oFill;
			nullable<CFont>			m_oFont;
			nullable<CNumFmt>		m_oNumFmt;
			nullable<CProtection>	m_oProtection;
		};
		class CDxfs : public WritingElementWithChilds<CDxf>
		{
		public:
			WritingElement_AdditionConstructors(CDxfs)
			CDxfs()
			{
			}
			virtual ~CDxfs()
			{
			}
			virtual void fromXML(XmlUtils::CXmlNode& node)
			{
			}
            virtual std::wstring toXML() const
			{
				return _T("");
			}
			virtual void toXML(NSStringUtils::CStringBuilder& writer) const
			{
				writer.WriteString(_T("<dxfs"));
				WritingStringNullableAttrInt(L"count", m_oCount, m_oCount->GetValue());
				writer.WriteString(_T(">"));

                for ( size_t i = 0; i < m_arrItems.size(); ++i)
                {
                    if (  m_arrItems[i] )
                    {
                        m_arrItems[i]->toXML(writer);
                    }
                }

				writer.WriteString(_T("</dxfs>"));
			}
			virtual void fromXML(XmlUtils::CXmlLiteReader& oReader)
			{
				ReadAttributes( oReader );

				if ( oReader.IsEmptyNode() )
					return;

				int nCurDepth = oReader.GetDepth();
				while( oReader.ReadNextSiblingNode( nCurDepth ) )
				{
					std::wstring sName = XmlUtils::GetNameNoNS(oReader.GetName());

					if ( _T("dxf") == sName )
						m_arrItems.push_back( new CDxf(oReader));
				}
			}

			virtual EElementType getType () const
			{
				return et_x_Dxfs;
			}

		private:
			void ReadAttributes(XmlUtils::CXmlLiteReader& oReader)
			{
				// Читаем атрибуты
				WritingElement_ReadAttributes_Start( oReader )
					WritingElement_ReadAttributes_Read_if     ( oReader, _T("count"), m_oCount )
				WritingElement_ReadAttributes_End( oReader )
			}
		public:
			nullable<SimpleTypes::CUnsignedDecimalNumber<>>		m_oCount;
		};
	} //Spreadsheet
} // namespace OOX

#endif // OOX_DXFS_FILE_INCLUDE_H_
