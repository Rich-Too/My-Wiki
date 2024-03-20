# Welcome to My Note site.

## [Mkdocs Commands](https://github.com/Rich-Too/My-Wiki/blob/master/docs/index2.md#mkdocs-commands)

- `mkdocs new [dir-name]` - Create a new project.
- `mkdocs serve` - Start the live-reloading docs server.
- `mkdocs build` - Build the documentation site.
- `mkdocs -h` - Print help message and exit.
- `mkdocs gh-deploy` - Deploy site on Github Pages, which will update gh-pages branch

## [Import font](https://github.com/Rich-Too/My-Wiki/blob/master/docs/index2.md#import-font)

**Global config**

```
:root {
  --md-text-font: 'Noto Serif SC', serif;
  --md-text-font-weight: bold; /* 设置字体加粗 */
  --md-code-font: "Roboto Mono";
}
```

**Frome google fonts**

[https://fonts.google.com/](https://fonts.google.com/) change CDN like below:

```yaml
extra_css:
  - https://fonts.loli.net/css?family=Noto+Serif+SC
  - https://fonts.loli.net/css?family=Open+Sans
  - https://fonts.loli.net/css?family=JetBrains+Mono
  - https://fonts.loli.net/css?family=Roboto+Mono
```