<?xml version="1.0" encoding="ISO-8859-1"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform"  >	
	
	<xsl:template match="/">
		
		<html>
			<head>
				<title><xsl:value-of select="/project/title" /> - Drupal <xsl:value-of select="/project/api_version" /> Module</title>
			</head>
			<body>
				
				<div class="wrap" id="mainWrap">
					<h1>Module Summary</h1>	 					
					<ul>Short Name: <xsl:value-of select="/project/short_name" /></ul>
					<ul>Latest Version: <xsl:value-of select="/project/releases/release/version" /></ul>
					<ul>Download: <a href="{/project/releases/release/download_link}"><xsl:value-of select="/project/releases/release/download_link" /></a></ul>
				</div>

				</body>
		</html>
	</xsl:template>
</xsl:stylesheet>
