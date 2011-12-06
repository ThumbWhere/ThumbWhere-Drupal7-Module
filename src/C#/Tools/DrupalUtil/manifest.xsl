<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:dc="http://purl.org/dc/elements/1.1/" >	

	
	<xsl:template match="/project">
		
		<html>
			<head>
				<title><xsl:value-of select="/project/title" /> - Drupal <xsl:value-of select="api_version" /> Module</title>
			</head>
			<body>
				
				<div class="wrap" id="mainWrap">
          <h1>Release Notes</h1>
            
					<h2><xsl:value-of select="title" /> Module For Drupal <xsl:value-of select="api_version" /></h2>

          <h3>
              Latest version
          </h3>
          <ul>
            Creator: <xsl:value-of select="dc:creator" />
          </ul>
          <ul>Short Name: <xsl:value-of select="short_name" /></ul>
					<ul>This Version: <xsl:value-of select="releases/release/version" /></ul>
					<ul>Download Url: <a href="${releases/release/download_link}"><xsl:value-of select="releases/release/download_link" /></a>
          </ul>          

          <!--
          <xsl:if test="not(recommended_major=releases/version_major)"><h1 color="red">When this was released, this was not the recommended major version.</h1></xsl:if>
          <xsl:if test="not(supported_majors=releases/version_major)"><h1 color="red">When this was released, this is not the current supported version.</h1></xsl:if>
          <xsl:if test="not(default_major=releases/version_major)"><h1 color="red">When this was released, this is not the current default version.</h1></xsl:if>
          -->
				</div>
        <hr/>
        <small>This has been autogenetrated by the ThumbWhere DrupalUtil appplication.</small>
      </body>
		</html>
	</xsl:template>
</xsl:stylesheet>
