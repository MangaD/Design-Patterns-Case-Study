// Some themes, like sphinx_rtd_theme, don’t respect the 
// myst_links_external_new_tab setting. JavaScript is a reliable way
// to enforce behavior consistently.
// Ensure all external links open in a new tab
document.addEventListener('DOMContentLoaded', function () {
    const links = document.querySelectorAll('a.external');
    links.forEach(link => {
        link.setAttribute('target', '_blank');
        link.setAttribute('rel', 'noopener noreferrer');
    });
});
