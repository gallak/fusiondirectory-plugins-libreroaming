<?php
/*
  This code is part of FusionDirectory (http://www.fusiondirectory.org/)
  Copyright (C) 2011-2018  FusionDirectory
  Copyright (C) 2018  Antoine Gallavardin

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
*/

class serviceLibreroamingProxy extends simpleService
{
  var $objectclasses = array('fdLibreRoamingProxyService');

  static function plInfo()
  {
    return array(
      'plShortName'   => _('LibreRoaming Proxy service '),
      'plDescription' => _('LibreRoaming Proxy service').' ('._('Services').')',
      'plIcon'        => 'geticon.php?context=devices&icon=terminal&size=16',
      'plProvidedAcls'  => parent::generatePlProvidedAcls(static::getAttributesInfo())
    );
  }

  static function getAttributesInfo ()
  {
      return array (
       'LibreRoamingProxyProperties' => array(
          'name' => _('Access Point Credential'),
          'attrs' => array(
            new StringAttribute(
              _('LibreRoamingProxyPort'),
              _('Port of the LibreRoaming Proxy'),
              'fdLibreRoamingProxyPort',
              TRUE),
            new StringAttribute(
              _('LibreRoamingProxyProxyFile'),
              _('Full path of proxy.conf file'),
              'fdLibreRoamingProxyProxyFile',
              TRUE),
            new StringAttribute(
              _('LibreRoamingProxyClientFile'),
              _('Full path of the Proxy client File'),
              'fdLibreRoamingProxyClientFile',
	      TRUE),
          ),
        ),
    );
  }
}

?>

