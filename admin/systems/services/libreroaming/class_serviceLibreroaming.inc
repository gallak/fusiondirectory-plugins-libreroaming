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

class serviceLibreroaming extends simpleService
{
  var $objectclasses = array('fdLibreRoamingService');

  static function plInfo()
  {
    return array(
      'plShortName'   => _('LibreRoaming service'),
      'plDescription' => _('LibreRoaming service').' ('._('Services').')',
      'plIcon'        => 'geticon.php?context=devices&icon=terminal&size=16',
      'plProvidedAcls'  => parent::generatePlProvidedAcls(static::getAttributesInfo())
    );
  }

  static function getAttributesInfo ()
  {
      return array (
       'AccessPointCredential' => array(
          'name' => _('Access Point Credential'),
          'attrs' => array(
            new StringAttribute(
              _('LibreRoamingShareKey'),
              _('Key share between radius client/server'),
              'fdLibreRoamingShareKey',
              TRUE),
            new StringAttribute(
              _('LibreRoamingClientTestAccount'),
              _('Test Account dedicated to this FreeRadius Server'),
              'fdLibreRoamingClientTestAccount',
              TRUE),
            new StringAttribute(
              _('LibreRoamingClientTestPassword'),
              _('Test password Account dedicated to this FreeRadius Server'),
              'fdLibreRoamingClientTestPassword',
	      TRUE),
            new StringAttribute(
              _('LibreRoamingPort'),
              _('Port dedicated to libreroaming service'),
              'fdLibreRoamingPort',
	      TRUE),
            )
          ),
        'AccessPointProperties' => array(
          'name' => _('Access Point Properties'),
          'attrs' => array(
            new SetAttribute (
              new SelectAttribute (
                _('EAPProvided'),
                _('EAP Type Provided'),
                'fdLibreRoamingEAPMethod', 
                FALSE,
                array('EAP-TLS', 'EAP-PEAP', 'EAP-MSCHAPv2','EAP-TTLS'),
                '',
                array(_('EAP-TLS'), _('EAP-PEAP'), _('EAP-MSCHAPv2'),_('EAP-TTLS'))
              )
            ),
            new SetAttribute (
              new SelectAttribute (
                _('wifiFederation'),
                _('Wifi Federation to connect ... Maybe One Day !!!'),
                'fdLibreRoamingFederation',
                FALSE,
                array('EDUROAM', 'FREE', 'FON'),
                '',
                array(_('Eduroam'), _('Free WIFI Secure'), _('FONetwork'))
              )
            ),
            new UsersAttribute(
              _('Technical contact'),
              _('Person in charge of this service'),
              'fdLibreRoamingTechnicalContact',
              TRUE
            ),
            new StringAttribute(
              _('LibreRoamingRealm'),
              _('LibreRoaming Realm valid for this service'),
              'fdLibreRoamingRealm',
              TRUE             
            ),
          )
        ),
      'AccessPoint' => array(
        'name' => _('List of Access Points'),
        'class' => array('fullwidth'),
        'template' => get_template_path('service_libreroaming.tpl', TRUE, dirname(__FILE__)),
        'attrs' => array (
          new OrderedArrayAttribute(
            new PipeSeparatedCompositeAttribute(
              _('Access Points provide by this host'),
              'fdLibreRoamingClientsLocation',
              array(
                new StringAttribute(
                  _('Name'),
                  _('Name of this Access point'),
                  'AccesPointName',
                  TRUE),
                new StringAttribute(
                  _('Description'),
                  _('Description of this Access Point'),
                  'AccessPointDesc',
                  FALSE),
                new StringAttribute(
                  _('GPSYCoord'),
                  _('GPS Y Coordonate'),
                  'GpsYCoord',
                  TRUE),
                new StringAttribute(
                  _('GPSXCoord'),
                  _('GPS X Coordonate'),
                  'GPSXCoord',
                  TRUE)
                )
              ),
              // no order
              FALSE,
              array(),
              // edit button
              TRUE
            )
          )
        ),
 
    );
  }
}

?>

