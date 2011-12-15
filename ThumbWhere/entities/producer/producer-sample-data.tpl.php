<?php

/**
 * @file
 * Example tpl file for theming a single producer-specific theme
 *
 * Available variables:
 * - $status: The variable to theme (while only show if you tick status)
 *
 * Helper variables:
 * - $producer: The Producer object this status is derived from
 */
?>

<div class="producer-status">
  <?php print '<strong>Producer Sample Data:</strong> ' . $producer_sample_data = ($producer_sample_data) ? 'Switch On' : 'Switch Off' ?>
</div>