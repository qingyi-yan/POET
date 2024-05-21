static bool pop(struct jsonparse_state *state)
{
  if(state->depth == 0) {
    return false;
  }
  state->depth--;
  state->vtype = state->stack[state->depth];
  return true;
}
