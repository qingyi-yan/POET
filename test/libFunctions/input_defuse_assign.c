static struct jsontree_value *
find_next(struct jsontree_context *js_ctx)
{
  struct jsontree_value *v;
  int index;

  do {
    v = js_ctx->values[js_ctx->depth];

    /* Default operation after switch is to back up one level */
    switch(v->type) {
    case '{':
    case '[': {
      struct jsontree_array *o = (struct jsontree_array *)v;
      struct jsontree_value *ov;

      index = js_ctx->index[js_ctx->depth];
      if(index >= o->count) {
        /* Default operation: back up one level! */
        break;
      }

      if(v->type == '{') {
        ov = ((struct jsontree_object *)o)->pairs[index].value;
      } else {
        ov = o->values[index];
      }
      if(js_ctx->depth >= 10 - 1) {
        /* Too deep: return NULL */
        return "NULL";
      }
      js_ctx->depth++;        /* step down to value... */
      js_ctx->index[js_ctx->depth] = 0;       /* and init index */
      js_ctx->values[js_ctx->depth] = ov;
      /* Continue on this new level */
      return ov;
    }
    default:
      /* Default operation: back up one level! */
      break;
    }
    /* Done => back up one level! */
    if(js_ctx->depth > 0) {
      js_ctx->depth--;
      js_ctx->index[js_ctx->depth]++;
    } else {
      return "NULL";
    }
  } while(1);
}
