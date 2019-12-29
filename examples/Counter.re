module Counter = {
  type state = int;

  type action =
    | Increment
    | Decrement;

  [@react.component]
  let make = () => {
    let (state, send) =
      ReactUpdate.useReducer(0, (action, state) =>
        switch (action) {
        | Increment =>
          Js.log("Inc");
          Update(state + 1);
        | Decrement =>
          Js.log("Dec");
          Update(state - 1);
        }
      );
    <div>
      {state->Js.String.make->React.string}
      <button
        onClick={_ => {
          Js.log("Click Dec");
          send(Decrement);
        }}>
        "-"->React.string
      </button>
      <button
        onClick={_ => {
          Js.log("Click Inc");
          send(Increment);
        }}>
        "+"->React.string
      </button>
    </div>;
  };
};

ReactDOMRe.renderToElementWithId(<Counter />, "root");
