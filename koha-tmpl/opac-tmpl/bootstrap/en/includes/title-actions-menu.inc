<div class="actions-menu noprint">
    [% IF Koha.Preference( 'RequestOnOpac' ) == 1 %]
        [% UNLESS ( items.norequests ) %]
            [% IF Koha.Preference( 'opacuserlogin' ) == 1 %]
                [% IF ( shelf AND op == 'view' ) # Lists view has more granular checking of hold availability %]
                    [% IF ( items.allow_onshelf_holds ) %]
                        <span class="actions"><a class="btn btn-link hold" href="/cgi-bin/koha/opac-reserve.pl?biblionumber=[% items.biblionumber | html %]"><i class="fa fa-fw fa-bookmark"></i> Place hold</a></span>
                    [% ELSE %]
                        [% IF ( items.itemsissued ) %]
                            <span class="actions"><a class="btn btn-link hold" href="/cgi-bin/koha/opac-reserve.pl?biblionumber=[% items.biblionumber | html %]"><i class="fa fa-fw fa-bookmark"></i> Place hold</a></span>
                        [% END %]
                    [% END %]
                [% ELSE %]
                    <span class="actions"><a class="btn btn-link hold" href="/cgi-bin/koha/opac-reserve.pl?biblionumber=[% items.biblionumber | html %]"><i class="fa fa-fw fa-bookmark"></i> Place hold</a></span>
                [% END %]
            [% END # / IF opacuserlogin %]
        [% END # / UNLESS items.norequests %]
    [% END # / RequestOnOpac %]

    [% IF ( Koha.Preference( 'opacuserlogin' ) == 1 ) %]
        [% IF items.artreqpossible %]
            <span class="actions"><a href="/cgi-bin/koha/opac-request-article.pl?biblionumber=[% items.biblionumber | uri %]" class="btn btn-link"><i class="fa fa-file-text"></i> Request article</a></span>
        [% END %]
    [% END %]

    [% IF ( TagsInputEnabled ) %]
        [% IF ( loggedinusername ) %]
            <span class="actions"><a id="tag_add[% items.biblionumber | html %]" href="#" class="tag_add btn btn-link"><i class="fa fa-tag"></i> Add tag</a></span>
            <div id="tagform[% items.biblionumber | html %]" class="tag_results_input" style="display:none;">
                <label for="newtag[% items.biblionumber | html %]">New tag(s), separated by a comma:</label>
                <input type="text" name="newtag[% items.biblionumber | html %]" id="newtag[% items.biblionumber | html %]" class="newtag" maxlength="100" />
                <input name="tagbutton" class="btn btn-small tagbutton" title="[% items.biblionumber | html %]" type="submit" value="Add" />
                <a class="cancel_tag_add" id="cancel[% items.biblionumber | html %]" href="#">(done)</a>
            </div>
            <span id="newtag[% items.biblionumber | html %]_status" class="tagstatus" style="display:none;">
                Tag status here.
            </span>
        [% ELSE %]
            <span class="actions"><span id="login4tags"><a class="btn btn-link loginModal-trigger" href="/cgi-bin/koha/opac-user.pl"><i class="fa fa-tag"></i> Log in to add tags</a></span></span>
        [% END # IF loggedinusername %]
    [% END # if TagsInputEnabled %]

    [% IF ( ( Koha.Preference( 'opacuserlogin' ) == 1 ) && loggedinusername && ( Koha.Preference( 'virtualshelves' ) == 1 ) ) %]
        [% IF ( shelf AND op == 'view' ) %]
            <span class="actions"><a href="/cgi-bin/koha/opac-addbybiblionumber.pl?biblionumber=[% items.biblionumber | uri %]" onclick="Dopop('opac-addbybiblionumber.pl?biblionumber=[% items.biblionumber | uri %]'); return false;" class="btn btn-link"><i class="fa fa-list"></i> Save to another list</a></span>
            [% IF can_remove_biblios %]
                <span class="actions"><a class="btn btn-link removefromlist" href="/cgi-bin/koha/opac-shelves.pl?op=remove_biblios&amp;shelfnumber=[% shelf.shelfnumber | html %]&amp;biblionumber=[% items.biblionumber | html %]"><i class="fa fa-remove"></i> Remove from this list</a></span>
            [% END %]
        [% ELSE %]
            <span class="actions"><a class="addtoshelf btn btn-link" href="/cgi-bin/koha/opac-addbybiblionumber.pl?biblionumber=[% items.biblionumber | html %]" onclick="Dopop('opac-addbybiblionumber.pl?biblionumber=[% items.biblionumber | html %]'); return false;"><i class="fa fa-list"></i> Save to lists</a></span>
        [% END # /IF ( shelf AND op == 'view' ) %]
    [% END # /IF Koha.Preference( 'opacuserlogin' ) %]

    [% IF Koha.Preference( 'opacbookbag' ) == 1 %]
        [% IF ( items.incart ) %]
            <span class="actions"><a data-biblionumber="[% items.biblionumber | html %]" class="btn btn-link cart cart[% items.biblionumber | html %]" href="#"><i class="fa fa-shopping-cart"></i> In your cart</a> <a data-biblionumber="[% items.biblionumber | html %]" class="btn btn-link remove cartRemove cartR[% items.biblionumber | html %]" href="#">(remove)</a></span>
        [% ELSE %]
            <span class="actions"><a data-biblionumber="[% items.biblionumber | html %]" class="btn btn-link addtocart cart cart[% items.biblionumber | html %]" href="#"><i class="fa fa-shopping-cart"></i> Add to cart</a> <a style="display:none;" data-biblionumber="[% items.biblionumber | html %]" class="btn btn-link remove cartRemove cartR[% items.biblionumber | html %]" href="#">(remove)</a></span>
        [% END %]
    [% END # / IF opacbookbag %]
</div>