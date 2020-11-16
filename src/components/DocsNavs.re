module SideNav = {
  module Styles = {
    open Css;
    let container =
      style([
        display(`none),
        media(Theme.MediaQuery.desktop, [display(`block)]),
      ]);
  };

  [@react.component]
  let make = (~currentSlug) => {
    module Item = SideNav.Item;
    module Section = SideNav.Section;
    let f = s => "/docs/" ++ s;
    <div className=Styles.container>
      <SideNav currentSlug>
        <Item title="Overview" slug="/docs" />
        <Item title="Getting Started" slug={f("getting-started")} />
        <Item title="My First Transaction" slug={f("my-first-transaction")} />
        <Item title="Become a Node Operator" slug={f("node-operator")} />
        <Item title="Contributing to Mina" slug={f("contributing")} />
        <Section title="Developers" slug={f("developers")}>
          <Item title="Developers Overview" slug="" />
          <Item title="Codebase Overview" slug="codebase-overview" />
          <Item title="Repository Structure" slug="directory-structure" />
          <Item title="Code Reviews" slug="code-reviews" />
          <Item title="Style Guide" slug="style-guide" />
          <Item title="Sandbox Node" slug="sandbox-node" />
          <Item title="GraphQL API" slug="graphql-api" />
        </Section>
        <Section title="Mina Protocol Architecture" slug={f("architecture")}>
          <Item title="Mina Overview" slug="" />
          <Item title="Lifecycle of a Payment" slug="lifecycle-payment" />
          <Item title="Consensus" slug="consensus" />
          <Item title="Proof of Stake" slug="proof-of-stake" />
          <Item title="Snark Workers" slug="snark-workers" />
        </Section>
        <Section title="SNARKs" slug={f("snarks")}>
          <Item title="SNARKs Overview" slug="" />
          <Item title="Getting started using SNARKs" slug="snarky" />
          <Item title="Which SNARK is right for me?" slug="constructions" />
          <Item title="The snarkyjs-crypto library" slug="snarkyjs-crypto" />
          <Item title="The snarky-universe library" slug="snarky-universe" />
        </Section>
        <Item title="Snapps" slug={f("snapps")} />
        <Item title="CLI Reference" slug={f("cli-reference")} />
        <Item title="Tokens" slug={f("tokens")} />
        <Item title="Troubleshooting" slug={f("troubleshooting")} />
        <Item title="FAQ" slug={f("faq")} />
        <Item title="Glossary" slug={f("glossary")} />
      </SideNav>
    </div>;
  };
};

module Dropdown = {
  module Styles = {
    open Css;

    let dropdown =
      style([
        position(`sticky),
        display(`block),
        top(`rem(2.)),
        marginBottom(`rem(4.)),
        zIndex(100),
        media(Theme.MediaQuery.desktop, [display(`none)]),
      ]);
  };

  [@react.component]
  let make = (~currentSlug) => {
    module Item = DropdownNav.Item;
    module Section = DropdownNav.Section;
    let f = s => "/docs/" ++ s;
    let getCurrentValue = s => {
      switch (s) {
      | "/docs/getting-started" => "Getting Started"
      | "/docs/my-first-transaction" => "My First Transaction"
      | "/docs/node-operator" => "Become a Node Operator"
      | "/docs/contributing" => "Contributing to Mina"

      | "/docs/developers" => "Developers Overview"
      | "/docs/developers/snarkyjs-crypto" => "Codebase Overview"
      | "/docs/developers/codebase-overview" => "Codebase Overview"
      | "/docs/developers/directory-structure" => "Repository Structure"
      | "/docs/developers/code-reviews" => "Code Reviews"
      | "/docs/developers/style-guide" => "Style Guide"
      | "/docs/developers/sandbox-node" => "Sandbox Node"
      | "/docs/developers/graphql-api" => "GraphQL API"

      | "/docs/architecture" => "Mina Overview"
      | "/docs/architecture/lifecycle-payment" => "Lifecycle of a Payment"
      | "/docs/architecture/consensus" => "Consensus"
      | "/docs/architecture/proof-of-stake" => "Proof of Stake"
      | "/docs/architecture/snark-workers" => "Snark Workers"

      | "/docs/snarks" => "SNARKs Overview"
      | "/docs/snarks/snarky" => "Getting started using SNARKs"
      | "/docs/snarks/constructions" => "Which SNARK is right for me?"
      | "/docs/snarks/snarkyjs-crypto" => "The snarkyjs-crypto library"
      | "/docs/snarks/snarky-universe" => "The snarky-universe library"

      | "/docs/snapps" => "Snapps"
      | "/docs/cli-reference" => "CLI Reference"
      | "/docs/tokens" => "Tokens"
      | "/docs/troubleshooting" => "Snapps"
      | "/docs/FAQ" => "Troubleshooting"
      | "/docs/glossary" => "Glossary"

      | _ => "Documentation"
      };
    };
    Js.log(currentSlug);
    <div className=Styles.dropdown>
      <DropdownNav currentSlug defaultValue={getCurrentValue(currentSlug)}>
        <Item title="Overview" slug="/docs" />
        <Item title="Getting Started" slug={f("getting-started")} />
        <Item title="My First Transaction" slug={f("my-first-transaction")} />
        <Item title="Become a Node Operator" slug={f("node-operator")} />
        <Item title="Contributing to Mina" slug={f("contributing")} />
        <Section title="Developers" slug={f("developers")}>
          <Item title="Developers Overview" slug="" />
          <Item title="Codebase Overview" slug="codebase-overview" />
          <Item title="Repository Structure" slug="directory-structure" />
          <Item title="Code Reviews" slug="code-reviews" />
          <Item title="Style Guide" slug="style-guide" />
          <Item title="Sandbox Node" slug="sandbox-node" />
          <Item title="GraphQL API" slug="graphql-api" />
        </Section>
        <Section title="Mina Protocol Architecture" slug={f("architecture")}>
          <Item title="Mina Overview" slug="" />
          <Item title="Lifecycle of a Payment" slug="lifecycle-payment" />
          <Item title="Consensus" slug="consensus" />
          <Item title="Proof of Stake" slug="proof-of-stake" />
          <Item title="Snark Workers" slug="snark-workers" />
        </Section>
        <Section title="SNARKs" slug={f("snarks")}>
          <Item title="SNARKs Overview" slug="" />
          <Item title="Getting started using SNARKs" slug="snarky" />
          <Item title="Which SNARK is right for me?" slug="constructions" />
          <Item title="The snarkyjs-crypto library" slug="snarkyjs-crypto" />
          <Item title="The snarky-universe library" slug="snarky-universe" />
        </Section>
        <Item title="Snapps" slug={f("snapps")} />
        <Item title="CLI Reference" slug={f("cli-reference")} />
        <Item title="Tokens" slug={f("tokens")} />
        <Item title="Troubleshooting" slug={f("troubleshooting")} />
        <Item title="FAQ" slug={f("faq")} />
        <Item title="Glossary" slug={f("glossary")} />
      </DropdownNav>
    </div>;
  };
};
