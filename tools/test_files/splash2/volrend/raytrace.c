
/*@;BEGIN(Func1=FunctionDecl)@*/void Trace_Ray(float foutx, float fouty, PIXEL *pixel_address)
{
  float ray[2][NM];
  float rmin,rmax; 
  float ray_min,ray_max;	
  long segment_zmin, segment_zmax;	                
  long span_zmin, span_zmax;	        	
  float sample[NM],	sample2[NM];	            
  long outz;		        
  long i,samplex,sampley,samplez;
  long sample2x,sample2y,sample2z;

  float box_zmin,box_zmax;
  long starting_level,level;
  float jump[NM],min_jump;
  float voxel[NM],next_voxel[NM];
  long ivoxel[NM],next_ivoxel[NM];
  BOOLEAN bit;

  float xalpha,yalpha,zalpha;
  float one_minus_xalpha,one_minus_yalpha,one_minus_zalpha;
  float weight,wopacity,wopacitysum,wcolorsum;
  float additional_opacity;

  float color;
  float opacity;
  float ray_color,ray_opacity;

  OPACITY *local_opc_address,*local2_opc_address;
  NORMAL *local_norm_address,*local2_norm_address;

  long pyr_offset1;	
  long pyr_offset2;	
  BYTE *pyr_address2;


  ray_color = (float)MIN_PIXEL;
  ray_opacity = MIN_OPACITY;

/*@;BEGIN(Nest1=Nest)@*/for (i=0; i<3; i++) {
    ray[0][i] = out_invvertex[0][0][0][i] +
      invjacobian[X][i]*foutx +
	invjacobian[Y][i]*fouty;
    ray[1][i] = ray[0][i] + invjacobian[Z][i]*image_zlen;
  }

  ray_min = 0.0;
  ray_max = 1.0;
/*@;BEGIN(Nest2=Nest)@*/for (i=0; i<NM; i++) {
    if (ABS(ray[1][i] - ray[0][i]) < SMALL) {
      if ((ray[0][i] < 0.0 &&
	   ray[1][i] < 0.0) ||
	  ((ray[0][i] > ((float)(opc_len[i]-1))) &&
	   (ray[1][i] > ((float)(opc_len[i]-1)))))
	return;
      else
	continue;
    }
    rmin = (0.0 - ray[0][i]) / (ray[1][i] - ray[0][i]);
    rmax = (((float)(opc_len[i]-1)) - ray[0][i]) / (ray[1][i] - ray[0][i]);
    //ray_min = MAX(MIN(rmin,rmax),ray_min);
/*@;BEGIN(Stmt1=Stmt)@*/ray_min = (((rmin) < (rmax) ? (rmin) : (rmax)) > ray_min ? ((rmin) < (rmax) ? (rmin) : (rmax)) : ray_min);
    //ray_max = MIN(MAX(rmin,rmax),ray_max);
/*@;BEGIN(Stmt2=Stmt)@*/ray_max = (((rmin) > (rmax) ? (rmin) : (rmax)) < ray_max ? ((rmin) > (rmax) ? (rmin) : (rmax)) : ray_max);
  }

  segment_zmin = ROUNDUP(image_zlen * ray_min);
  segment_zmax = ROUNDDOWN(image_zlen * ray_max);

  if (segment_zmax < segment_zmin) return; 

  box_zmin = (float)segment_zmin;
  voxel[X] = ray[0][X] + invjacobian[Z][X]*box_zmin;
  voxel[Y] = ray[0][Y] + invjacobian[Z][Y]*box_zmin;
  voxel[Z] = ray[0][Z] + invjacobian[Z][Z]*box_zmin;
  ivoxel[X] = VXEL(voxel[X],invjacobian[Z][X]);
  ivoxel[Y] = VXEL(voxel[Y],invjacobian[Z][Y]);
  ivoxel[Z] = VXEL(voxel[Z],invjacobian[Z][Z]);
  starting_level = MIN(pyr_highest_level,pyr_levels-1);
  level = starting_level;

/*Nest3*/while (1) {

    /*bit = PYR(level,ivoxel[Z]>>level,
	      ivoxel[Y]>>level,
	      ivoxel[X]>>level);*/
    pyr_offset1 = ((ivoxel[Z]>>level)*pyr_len[level][Y]+(ivoxel[Y]>>level)) * 
                 pyr_len[level][X]+(ivoxel[X]>>level);
    pyr_offset2 = pyr_offset1 & 7;
    pyr_address2=pyr_address[level] + (pyr_offset1>>3);
/*@;BEGIN(Stmt3=Stmt)@*/bit = (*pyr_address2 >> pyr_offset2) & 1;
    if (bit && level > pyr_lowest_level) {
      level--;
      continue;
    }

    min_jump = BIG;
    if (invjacobian[Z][X] > SMALL) {
      jump[X] = invinvjacobian[Z][X] *
	(((ROUNDDOWN(voxel[X])>>level)+1)*
	 pyr_voxlen[level][X]-voxel[X]);
      min_jump = MIN(min_jump,jump[X]);
    }
    else if (invjacobian[Z][X] < -SMALL) {
      jump[X] = invinvjacobian[Z][X] *
	((STEPDOWN(voxel[X])>>level)*
	 pyr_voxlen[level][X]-voxel[X]);
      min_jump = MIN(min_jump,jump[X]);
      }
    if (invjacobian[Z][Y] > SMALL) {
      jump[Y] = invinvjacobian[Z][Y] *
	(((ROUNDDOWN(voxel[Y])>>level)+1)*
	 pyr_voxlen[level][Y]-voxel[Y]);
      min_jump = MIN(min_jump,jump[Y]);
    }
    else if (invjacobian[Z][Y] < -SMALL) {
      jump[Y] = invinvjacobian[Z][Y] *
	((STEPDOWN(voxel[Y])>>level)*
	 pyr_voxlen[level][Y]-voxel[Y]);
      min_jump = MIN(min_jump,jump[Y]);
    }
    if (invjacobian[Z][Z] > SMALL) {
      jump[Z] = invinvjacobian[Z][Z] *
	(((ROUNDDOWN(voxel[Z])>>level)+1)*
	 pyr_voxlen[level][Z]-voxel[Z]);
      min_jump = MIN(min_jump,jump[Z]);
    }
    else if (invjacobian[Z][Z] < -SMALL) {
      jump[Z] = invinvjacobian[Z][Z] *
	((STEPDOWN(voxel[Z])>>level)*
	 pyr_voxlen[level][Z]-voxel[Z]);
      min_jump = MIN(min_jump,jump[Z]);
    }
    box_zmax = box_zmin + min_jump;

    if (bit) {
      break;
    }

  (next_box):
    if (box_zmax >= (float)segment_zmax) {
      goto end_of_segment;
    }
    box_zmin = box_zmax;

    next_voxel[X] = voxel[X] + invjacobian[Z][X]*min_jump;
    next_voxel[Y] = voxel[Y] + invjacobian[Z][Y]*min_jump;
    next_voxel[Z] = voxel[Z] + invjacobian[Z][Z]*min_jump;
    next_ivoxel[X] = VXEL(next_voxel[X],invjacobian[Z][X]);
    next_ivoxel[Y] = VXEL(next_voxel[Y],invjacobian[Z][Y]);
    next_ivoxel[Z] = VXEL(next_voxel[Z],invjacobian[Z][Z]);

/*Nest4*/while (level < starting_level) {
      if(next_ivoxel[X]>>(level+1) !=
	 ivoxel[X]>>(level+1) ||
	 next_ivoxel[Y]>>(level+1) !=
	 ivoxel[Y]>>(level+1) ||
	 next_ivoxel[Z]>>(level+1) !=
	 ivoxel[Z]>>(level+1)) {
	level++;
      }
      else
	break;
    }

    voxel[X] = next_voxel[X];
    voxel[Y] = next_voxel[Y];
    voxel[Z] = next_voxel[Z];
    ivoxel[X] = next_ivoxel[X];
    ivoxel[Y] = next_ivoxel[Y];
    ivoxel[Z] = next_ivoxel[Z];
  }
  span_zmin = ROUNDUP(box_zmin);
  span_zmax = MIN((long)box_zmax,segment_zmax);

  if (span_zmax < span_zmin) goto next_box;

  sample[X] = ray[0][X] + invjacobian[Z][X]*span_zmin;
  sample[Y] = ray[0][Y] + invjacobian[Z][Y]*span_zmin;
  sample[Z] = ray[0][Z] + invjacobian[Z][Z]*span_zmin;

/*@;BEGIN(Nest5=Nest)@*/for (outz=span_zmin; outz<=span_zmax; outz++) {

    samplex=(long)sample[X];
    sampley=(long)sample[Y];
    samplez=(long)sample[Z];

    /*bit=PYR(0,samplez,sampley,samplex);*/
    pyr_offset1 = (samplez*pyr_len[0][Y]+sampley) * pyr_len[0][X]+samplex;
    pyr_offset2 = pyr_offset1 & 7;
    pyr_address2 = pyr_address[0] + (pyr_offset1>>3);
/*@;BEGIN(Stmt4=Stmt)@*/bit = (*pyr_address2>>pyr_offset2)&1;
      if (!bit) goto end_of_sample;

    sample2[X] = MIN(sample[X],in_max[X]);
    sample2[Y] = MIN(sample[Y],in_max[Y]);
    sample2[Z] = MIN(sample[Z],in_max[Z]);

    sample2x = (long)sample2[X];
    sample2y = (long)sample2[Y];
    sample2z = (long)sample2[Z];

    xalpha = sample2[X]-sample2x++;
    yalpha = sample2[Y]-sample2y;
    zalpha = sample2[Z]-sample2z;

    local_opc_address = OPC_ADDRESS(sample2z,sample2y,sample2x);
    local_norm_address = NORM_ADDRESS(sample2z,sample2y,sample2x,Z);

    one_minus_xalpha = 1.0 - xalpha;
    one_minus_yalpha = 1.0 - yalpha;
    one_minus_zalpha = 1.0 - zalpha;

    weight = xalpha * one_minus_yalpha * one_minus_zalpha;
    wopacity = *local_opc_address-- * weight;
    color = SHD(*local_norm_address--);
    wcolorsum = color * wopacity;
    wopacitysum = wopacity;

    weight = one_minus_xalpha * one_minus_yalpha * one_minus_zalpha;
    wopacity = *local_opc_address * weight;
    color = SHD(*local_norm_address);
    wcolorsum += color * wopacity;
    wopacitysum += wopacity;

    weight = xalpha * yalpha * one_minus_zalpha;
    local2_opc_address = local_opc_address+opc_xlen;
    local2_norm_address = local_norm_address+norm_xlen;
    wopacity = *local2_opc_address-- * weight;
    color = SHD(*local2_norm_address--);
    wcolorsum += color * wopacity;
    wopacitysum += wopacity;

    weight = one_minus_xalpha * yalpha * one_minus_zalpha;
    wopacity = *local2_opc_address * weight;
    color = SHD(*local2_norm_address);
    wcolorsum += color * wopacity;
    wopacitysum += wopacity;

    weight = xalpha * one_minus_yalpha * zalpha;
    local_opc_address = local_opc_address+opc_xylen;
    local_norm_address = local_norm_address+norm_xylen;
    wopacity = *local_opc_address-- * weight;
    color = SHD(*local_norm_address--);
    wcolorsum += color * wopacity;
    wopacitysum += wopacity;

    weight = one_minus_xalpha * one_minus_yalpha * zalpha;
    wopacity = *local_opc_address * weight;
    color = SHD(*local_norm_address);
    wcolorsum += color * wopacity;
    wopacitysum += wopacity;

    weight = xalpha * yalpha * zalpha;
    local2_opc_address = local_opc_address+opc_xlen;
    local2_norm_address = local_norm_address+norm_xlen;
    wopacity = *local2_opc_address-- * weight;
    color = SHD(*local2_norm_address--);
    wcolorsum += color * wopacity;
    wopacitysum += wopacity;

    weight = one_minus_xalpha * yalpha * zalpha;
    wopacity = *local2_opc_address * weight;
    color = SHD(*local2_norm_address);
    wcolorsum += color * wopacity;
    wopacitysum += wopacity;

    opacity = wopacitysum * INV_MAX_OPC;
    color = wcolorsum * INV_MAX_OPC;


    color *= depth_cueing[outz];

    additional_opacity = opacity * (1.0-ray_opacity);
    ray_color += color * (1.0-ray_opacity);
    ray_opacity += additional_opacity;

    if (ray_opacity > opacity_cutoff) {
      goto end_of_ray;
    }

  (end_of_sample):;
    sample[X] += invjacobian[Z][X];
    sample[Y] += invjacobian[Z][Y];
    sample[Z] += invjacobian[Z][Z];
  }

    goto next_box;

 (end_of_segment):;

  if (ray_opacity <= opacity_epsilon) return;

 (end_of_ray):;

  additional_opacity = 1.0 - ray_opacity;
  ray_color += *pixel_address * additional_opacity;
  *pixel_address = NINT(ray_color);
}
