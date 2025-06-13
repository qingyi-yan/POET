
(set-logic ALL)
(set-option :produce-models true)
(set-option :produce-unsat-cores true)

; Memory cells
(define-fun memory_cell ((l Int)) Bool
  (and (<= 0 l) (<= l 5))
)

; Position and implementation variables
(declare-const p0_in0 Int)
(assert (memory_cell p0_in0))(declare-const p2_in0 Int)
(assert (memory_cell p2_in0))(declare-const pn_in0 Int)
(assert (memory_cell pn_in0))(declare-const p1_in0 Int)
(assert (memory_cell p1_in0))
(declare-const p_unknown_out0 Int)
(assert (memory_cell p_unknown_out0))(declare-const p_new_out0 Int)
(assert (memory_cell p_new_out0))(declare-const p0_out0 Int)
(assert (memory_cell p0_out0))(declare-const p2_out0 Int)
(assert (memory_cell p2_out0))(declare-const pn_out0 Int)
(assert (memory_cell pn_out0))(declare-const p1_out0 Int)
(assert (memory_cell p1_out0))
(assert (! (not (= p_new_out0 p_unknown_out0)) :named p_unique_p_new_p_unknown_out0))(assert (! (not (= p_new_out0 p0_out0)) :named p_unique_p_new_p0_out0))(assert (! (not (= p_new_out0 pn_out0)) :named p_unique_p_new_pn_out0))(assert (! (not (= p_new_out0 p1_out0)) :named p_unique_p_new_p1_out0))

; definition of anchor/member variables
(declare-const begin_in0 Int)
(assert (memory_cell begin_in0))
(declare-const begin_out0 Int)
(assert (memory_cell begin_out0))(declare-const head_in0 Int)
(assert (memory_cell head_in0))
(declare-const head_out0 Int)
(assert (memory_cell head_out0))

; nextto relations
(define-fun nextto_in0 ((l Int) (r Int)) Bool
  false)
(define-fun nextto_out0 ((l Int) (r Int)) Bool
  (or (and (= l p_unknown_out0)  (= r p_new_out0) (not (= l r)))(and (= l p2_out0)  (= r p0_out0) (not (= l r)))))
(assert (!(nextto_out0 p_unknown_out0 p_new_out0) :named nextto_out0_p_unknown_p_new))(assert (!(nextto_out0 p2_out0 p0_out0) :named nextto_out0_p2_p0))

; reachable relations
(define-fun-rec reachable_in0 ((l Int) (r Int)) Bool
  (or (and (= l p1_in0)  (= r pn_in0) (<= l r))(and (= l p0_in0)  (= r p1_in0) (<= l r))
    (= l r)
    (nextto_in0 l r)
    (exists ((m Int)) (and (nextto_in0 l m) (reachable_in0 m r)))
    (exists ((m Int)) (and (reachable_in0 l m) (nextto_in0 m r)))))
(assert (!(reachable_in0 p1_in0 pn_in0) :named reach_in0_p1_pn))(assert (!(reachable_in0 p0_in0 p1_in0) :named reach_in0_p0_p1))(define-fun-rec reachable_out0 ((l Int) (r Int)) Bool
  (or (and (= l p1_out0)  (= r pn_out0) (<= l r))(and (= l p0_out0)  (= r p1_out0) (<= l r))
    (= l r)
    (nextto_out0 l r)
    (exists ((m Int)) (and (nextto_out0 l m) (reachable_out0 m r)))
    (exists ((m Int)) (and (reachable_out0 l m) (nextto_out0 m r)))))
(assert (!(reachable_out0 p1_out0 pn_out0) :named reach_out0_p1_pn))(assert (!(reachable_out0 p0_out0 p1_out0) :named reach_out0_p0_p1))

; aliases
(assert (! (not (= head_in0 0)) :named alias_head_in0_0))(assert (! (not (= begin_in0 0)) :named alias_begin_in0_0))(assert (! (= head_in0 p0_in0) :named alias_head_in0_p0_in0))(assert (! (= begin_in0 p0_in0) :named alias_begin_in0_p0_in0))(assert (! (= head_out0 p0_out0) :named alias_head_out0_p0_out0))(assert (! (= begin_out0 p2_out0) :named alias_begin_out0_p2_out0))(assert (! (= p0_in0 p0_out0) :named unchanged_p0_in0_out0))(assert (! (= pn_in0 pn_out0) :named unchanged_pn_in0_out0))(assert (! (= p1_in0 p1_out0) :named unchanged_p1_in0_out0))

; binding of member variables
(assert (! (or (= begin_out0 head_out0) (and (= begin_out0 0) (nextto_out0 begin_out0 head_out0))) :named binding_begin_head_out0))(assert (! (or (= begin_in0 head_in0) (and (= begin_in0 0) (nextto_in0 begin_in0 head_in0))) :named binding_begin_head_in0))

(check-sat)
(get-model)
(get-unsat-core)