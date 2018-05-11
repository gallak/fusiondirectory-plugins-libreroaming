<fieldset id="{$sectionId}" class="plugin-section{$sectionClasses}">
  <legend><span><label for="{$attributes.fdLibreRoamingClientsLocation.htmlid}">{$section}</label></span></legend>
  <div>
  <table>
    <tr>
      <td title="{$attributes.fdLibreRoamingClientsLocation.description}" colspan="4">
        {eval var=$attributes.fdLibreRoamingClientsLocation.input}
      </td>
    </tr>
    <tr>
      <td title="{$attributes.accessPointName.description}">
        <label for="{$attributes.accessPointName.htmlid}">
          {eval var=$attributes.accessPointName.label}
        </label>
      </td>
      <td title="{$attributes.accessPointDesc.description}">
        <label for="{$attributes.accessPointDesc.htmlid}">
          {eval var=$attributes.accessPointDesc.label}
        </label>
      </td>
      <td title="{$attributes.GpsYCoord.description}">
        <label for="{$attributes.GpsYCoord.htmlid}">
          {eval var=$attributes.GpsYCoord.label}
        </label>
      </td>
      <td title="{$attributes.GpsXCoord.description}">
        <label for="{$attributes.GpsXCoord.htmlid}">
          {eval var=$attributes.GpsXCoord.label}
        </label>
      </td>
    </tr>
    <tr>
      <td title="{$attributes.fdLibreRoamingClientsLocation_buttons.description}" colspan="4">
        {eval var=$attributes.fdLibreRoamingClients_buttons.input}
      </td>
    </tr>
  </table>
  </div>
</fieldset>
