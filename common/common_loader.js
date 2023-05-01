window.addEventListener("DOMContentLoaded", () => {
  const JSGen = (src, integrity) => {
    const script = document.createElement("script");
    script.src = src;
    script.integrity = integrity;
    script.crossOrigin = "anonymous";
    return script;
  };

  fetch("/common/common.html")
    .then((r) => r.text())
    .then((t) => {
      document.head.innerHTML += t;

      window.katexOpt = {
        ignoredTags: ["script", "noscript", "style", "textarea", "option"],
        delimiters: [
          { left: "$$", right: "$$", display: true },
          { left: "$", right: "$", display: false },
          { left: "\\(", right: "\\)", display: false },
          { left: "\\[", right: "\\]", display: true },
        ],
      };
    })
    .then(() => {
      document.head.appendChild(
        JSGen(
          "https://cdn.jsdelivr.net/npm/bootstrap@5.0.2/dist/js/bootstrap.bundle.min.js",
          "sha384-MrcW6ZMFYlzcLA8Nl+NtUVF0sA7MsXsP1UyJoMp4YLEuNSfAP+JcXn/tWtIaxVXM"
        )
      );

      const katex = JSGen(
        "https://cdn.jsdelivr.net/npm/katex@0.16.0/dist/katex.min.js",
        "sha384-X/XCfMm41VSsqRNQgDerQczD69XqmjOOOwYQvr/uuC+j4OPoNhVgjdGFwhvN02Ja"
      );
      katex.addEventListener("load", () => {
        const ar = JSGen(
          "https://cdn.jsdelivr.net/npm/katex@0.16.0/dist/contrib/auto-render.min.js",
          "sha384-+XBljXPPiv+OzfbB3cVmLHf4hdUFHlWNZN5spNQ7rmHTXpd7WvJum6fIACpNNfIR"
        );
        ar.addEventListener("load", () => {
          window.renderMathInElement(document.body, window.katexOpt);
        });
        document.head.appendChild(ar);
      });
      document.head.append(katex);
    });
});
