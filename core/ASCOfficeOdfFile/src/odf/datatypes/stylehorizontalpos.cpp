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

#include "stylehorizontalpos.h"

#include <boost/algorithm/string.hpp>
#include <ostream>

namespace cpdoccore { namespace odf_types { 

std::wostream & operator << (std::wostream & _Wostream, const horizontal_pos & _Val)
{
    switch(_Val.get_type())
    {
    case horizontal_pos::Left:
        _Wostream << L"left";
        break;
    case horizontal_pos::Center:
        _Wostream << L"center";
        break;
    case horizontal_pos::Right:
        _Wostream << L"right";
        break;
    case horizontal_pos::FromLeft:
        _Wostream << L"from-left";
        break;
    case horizontal_pos::Inside:
        _Wostream << L"inside";
        break;
    case horizontal_pos::Outside:
        _Wostream << L"outside";
        break;
    case horizontal_pos::FromInside:
        _Wostream << L"from-inside";
        break;
    default:
        break;
    }
    return _Wostream;    
}

horizontal_pos horizontal_pos::parse(const std::wstring & Str)
{
    std::wstring tmp = Str;
    boost::algorithm::to_lower(tmp);

    if (tmp == L"left")
        return horizontal_pos( Left );
    else if (tmp == L"center")
        return horizontal_pos( Center );
    else if (tmp == L"right")
        return horizontal_pos( Right );
    else if (tmp == L"from-left")
        return horizontal_pos( FromLeft );
    else if (tmp == L"inside")
        return horizontal_pos( Inside );
    else if (tmp == L"outside")
        return horizontal_pos( Outside );
    else if (tmp == L"from-inside")
        return horizontal_pos( FromInside );
    else
    {
        BOOST_THROW_EXCEPTION( errors::invalid_attribute() );        
        return horizontal_pos( Left );
    }
}

} }
