<div id="funnelback-results-page">

<?php if ($summary['total'] > 0): ?>

<div id="funnelback-summary">
<?php print $summary['start'] ?> - <?php print $summary['end'] ?> 
          search results of <?php print $summary['total'] ?>
          for <strong><?php print $summary['query']; ?></strong>
</div>

<?php if (!empty($best_bets)): ?>
<div id="funnelback-bestbets">

<?php foreach($best_bets as $best_bet): ?>

  <div class="funnelback-bestbet">
    <h4>Recommended</h4>
    <h3><a href="<?php print $best_bet['click_url'] ?>" title="<?php print $best_bet['live_url'] ?>"><?php print $best_bet['title'] ?></a></h3>
    <p class="desc"><?php print $best_bet['desc'] ?></p>
    <p><cite><?php print $best_bet['live_url'] ?></cite></p>
  </div>

<?php endforeach; ?>
</div>
<?php endif; ?>
<?php endif; ?>

<?php // always show spelling options ?>

<?php if (!empty($spell)): ?>
<div id="funnelback-spell">
  <p>Did you mean: 
  <?php foreach ($spell as $suggestion): ?>
    <a href='?<?php print $suggestion['url'] ?>'><?php print $suggestion['text'] ?></a>
  <?php endforeach; ?>
  </p>
</div>
<?php endif; ?>

<?php if ($summary['total'] > 0): ?>

<ul id="funnelback-results">
<?php foreach ($items as $item): ?>
  <li class="funnelback-result">
    <h3><a href="<?php print $item['click_url'] ?>" title="<?php print $item['live_url'] ?>"><?php print $item['title'] ?></a></h3>
    <p>
      <?php if ($item['date'] != 'No Date'): ?>
        <span class="date"><?php print $item['date']; ?></span>
      <?php endif; ?>
      <span class="summary"><?php print $item['summary']; ?></span></p>
      <p><cite><?php print $item['live_url'] ?></cite> - <a href="<?php print $summary['base_url'].$item['cache_url']; ?>">Cached</a>
    </p>
  </li>
<?php endforeach; ?>
</ul>

<?php else: ?>

<p>Your search for <strong><?php print $summary['query'] ?></strong> did not return any results.
<p>Please ensure that you:
<ul class="no-result">
  <li>are not using any advanced search operators like + - | " etc.</li>
  <li>expect this document to exist within this site</li>
  <li>have permission to see any documents that may match your query</li>
</ul>
</p>

<?php endif; ?>

<?php print $pager ?>

<a href="http://www.funnelback.com"><img src="<?php print base_path().path_to_theme() ?>/img/powered-by-funnelback.gif" alt="Powered by Funnelback" width="102" height="32" /></a>


</div>

